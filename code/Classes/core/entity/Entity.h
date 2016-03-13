#ifndef __CORE_ENTITY_ENTITY_H__
#define __CORE_ENTITY_ENTITY_H__

#include "cocos2d.h"

class Entity : public cocos2d::Node
{
public:
	CREATE_FUNC(Entity);

	Entity();
	~Entity();

	virtual bool init();

private:

};

#endif
