#include "LayerEntity.h"
#include "model/define/DfinesRes.h"

USING_NS_CC;

LayerEntity::LayerEntity() : _handleEntity(nullptr), _handleBox2d(nullptr)
{
}

LayerEntity::~LayerEntity()
{
	CC_SAFE_RELEASE_NULL(_handleEntity);
	CC_SAFE_RELEASE_NULL(_handleBox2d);
}

void LayerEntity::startEngine()
{
	scheduleUpdate();//开始游戏循环
}

void LayerEntity::spriteAdd(const cocos2d::Vec2& location)
{
	log("Add sprite %0.2f x %0.2f", location.x, location.y);

	auto sprite = Sprite::create(RES_ENTITY);
	sprite->setPosition(Vec2(location.x, location.y));
	addChild(sprite);

	_handleBox2d->createBody(sprite);
}

bool LayerEntity::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_handleEntity = HandleEntity::create();
		_handleEntity->retain();
		_handleEntity->setLayerEntity(this);

		_handleBox2d = HandleBox2d::create();
		_handleBox2d->retain();

		auto listener = EventListenerTouchOneByOne::create();
		listener->setSwallowTouches(true);
		listener->onTouchBegan = CC_CALLBACK_2(LayerEntity::onTouchBegan, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

		isInit = true;
	} while (0);

	return isInit;
}

bool LayerEntity::onTouchBegan(Touch *touch, Event *event)
{
	auto target = (Node*)event->getCurrentTarget();
	auto location = target->convertToNodeSpace(touch->getLocation());
	auto sizeTarget = target->getContentSize();
	auto rect = Rect(0.0f, 0.0f, sizeTarget.width, sizeTarget.height);
	if (rect.containsPoint(location))
	{
		_handleEntity->entityAdd(location);
		return true;
	}
	return false;
}

void LayerEntity::update(float dt)
{
	_handleBox2d->updateByTime(dt);
}
