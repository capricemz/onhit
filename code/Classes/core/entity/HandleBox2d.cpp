#include "HandleBox2d.h"
#include "model/define/DfinesValue.h"

USING_NS_CC;

HandleBox2d::HandleBox2d() : _world(nullptr)
{
}

HandleBox2d::~HandleBox2d()
{
	CC_SAFE_DELETE(_world);
}

bool HandleBox2d::init()
{
	auto isInit = false;

	do
	{
		b2Vec2 gravity;//重力参数
		gravity.Set(0.0f, NUM_GRAVITY);
		_world = new b2World(gravity);//创建世界 
		_world->SetAllowSleeping(true);// 允许物体是否休眠
		_world->SetContinuousPhysics(true);// 开启连续物理测试

		b2BodyDef bodyDefGround;//地面物体定义
		bodyDefGround.position.Set(0.0f, 0.0f);//左下角

		b2Body* bodyGround = _world->CreateBody(&bodyDefGround);//创建地面物体 

		auto sizeVisible = Director::getInstance()->getVisibleSize();

		b2EdgeShape shapeGround;//定义一个有边的形状 
		
		shapeGround.Set(b2Vec2(0.0f, 0.0f), b2Vec2(0.0f, sizeVisible.width / NUM_PTM_RATIO));// 底部
		bodyGround->CreateFixture(&shapeGround, 0.0f);//使用夹具固定形状到物体上

		shapeGround.Set(b2Vec2(0.0f, sizeVisible.height / NUM_PTM_RATIO), b2Vec2(sizeVisible.width / NUM_PTM_RATIO, sizeVisible.height / NUM_PTM_RATIO));// 顶部
		bodyGround->CreateFixture(&shapeGround, 0.0f);

		shapeGround.Set(b2Vec2(0.0f, sizeVisible.height / NUM_PTM_RATIO), b2Vec2(0.0f, 0.0f));// 左边
		bodyGround->CreateFixture(&shapeGround, 0.0f);

		shapeGround.Set(b2Vec2(sizeVisible.width / NUM_PTM_RATIO, sizeVisible.height / NUM_PTM_RATIO), b2Vec2(sizeVisible.width / NUM_PTM_RATIO, 0.0f));// 右边
		bodyGround->CreateFixture(&shapeGround, 0.0f);

		isInit = true;
	} while (0);

	return isInit;
}

void HandleBox2d::updateBySubject(va_list values)
{

}

void HandleBox2d::createBody(cocos2d::Sprite* sprite)
{
	auto positionSprite = sprite->getPosition();
	auto sizeSprite = sprite->getContentSize();
	//物体定义
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(positionSprite.x / NUM_PTM_RATIO, positionSprite.y / NUM_PTM_RATIO);
	auto body = _world->CreateBody(&bodyDef);
	body->SetUserData(sprite);
	// 定义盒子形状
	b2PolygonShape shape;
	shape.SetAsBox((sizeSprite.width / NUM_PTM_RATIO) * 0.5f, (sizeSprite.height / NUM_PTM_RATIO) * 0.5f);
	
	b2FixtureDef fixtureDef;// 夹具定义
	fixtureDef.shape = &shape;//设置夹具的形状
	fixtureDef.density = 1.0f;//设置密度
	fixtureDef.friction = 0.3f;//设置摩擦系数
	body->CreateFixture(&fixtureDef);//使用夹具固定形状到物体上
}

void HandleBox2d::updateByTime(float dt)
{
	_world->Step(dt, NUM_VELOCITY_ITERATIONS, NUM_POSITION_ITERATIONS);

	b2Body* body = _world->GetBodyList();
	while (body != nullptr)
	{
		auto bodyNow = body;
		body = body->GetNext();
		auto sprite = (Sprite*)bodyNow->GetUserData();
		if (sprite != nullptr)
		{
			sprite->setPosition(Vec2(bodyNow->GetPosition().x * NUM_PTM_RATIO, bodyNow->GetPosition().y * NUM_PTM_RATIO));
			sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(bodyNow->GetAngle()));
		}
	}
}
