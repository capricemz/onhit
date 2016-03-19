#ifndef __CORE_ENTITY_HANDLE_BOX2D_H__
#define __CORE_ENTITY_HANDLE_BOX2D_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "common/observer/Observer.h"

class HandleBox2d : public cocos2d::Ref, Observer
{
public:
	CREATE_FUNC(HandleBox2d);

	HandleBox2d();
	~HandleBox2d();

	virtual bool init();

	virtual void updateBySubject(va_list values);

	void createBody(cocos2d::Sprite* sprite);

	void updateByTime(float dt);

	CC_SYNTHESIZE(b2World*, _world, World);

private:

};

#endif