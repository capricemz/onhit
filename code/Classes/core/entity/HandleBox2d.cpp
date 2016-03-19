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
		b2Vec2 gravity;//��������
		gravity.Set(0.0f, NUM_GRAVITY);
		_world = new b2World(gravity);//�������� 
		_world->SetAllowSleeping(true);// ���������Ƿ�����
		_world->SetContinuousPhysics(true);// ���������������

		b2BodyDef bodyDefGround;//�������嶨��
		bodyDefGround.position.Set(0.0f, 0.0f);//���½�

		b2Body* bodyGround = _world->CreateBody(&bodyDefGround);//������������ 

		auto sizeVisible = Director::getInstance()->getVisibleSize();

		b2EdgeShape shapeGround;//����һ���бߵ���״ 
		
		shapeGround.Set(b2Vec2(0.0f, 0.0f), b2Vec2(0.0f, sizeVisible.width / NUM_PTM_RATIO));// �ײ�
		bodyGround->CreateFixture(&shapeGround, 0.0f);//ʹ�üо߹̶���״��������

		shapeGround.Set(b2Vec2(0.0f, sizeVisible.height / NUM_PTM_RATIO), b2Vec2(sizeVisible.width / NUM_PTM_RATIO, sizeVisible.height / NUM_PTM_RATIO));// ����
		bodyGround->CreateFixture(&shapeGround, 0.0f);

		shapeGround.Set(b2Vec2(0.0f, sizeVisible.height / NUM_PTM_RATIO), b2Vec2(0.0f, 0.0f));// ���
		bodyGround->CreateFixture(&shapeGround, 0.0f);

		shapeGround.Set(b2Vec2(sizeVisible.width / NUM_PTM_RATIO, sizeVisible.height / NUM_PTM_RATIO), b2Vec2(sizeVisible.width / NUM_PTM_RATIO, 0.0f));// �ұ�
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
	//���嶨��
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(positionSprite.x / NUM_PTM_RATIO, positionSprite.y / NUM_PTM_RATIO);
	auto body = _world->CreateBody(&bodyDef);
	body->SetUserData(sprite);
	// ���������״
	b2PolygonShape shape;
	shape.SetAsBox((sizeSprite.width / NUM_PTM_RATIO) * 0.5f, (sizeSprite.height / NUM_PTM_RATIO) * 0.5f);
	
	b2FixtureDef fixtureDef;// �о߶���
	fixtureDef.shape = &shape;//���üоߵ���״
	fixtureDef.density = 1.0f;//�����ܶ�
	fixtureDef.friction = 0.3f;//����Ħ��ϵ��
	body->CreateFixture(&fixtureDef);//ʹ�üо߹̶���״��������
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
