#ifndef _CORE_ENTITY_ENTITY_H_
#define _CORE_ENTITY_ENTITY_H_

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
