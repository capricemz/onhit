#ifndef __CORE_ENTITY_I_LAYER_ENTITY_H__
#define __CORE_ENTITY_I_LAYER_ENTITY_H__

#include "cocos2d.h"

class ILayerEntity
{
public:
	virtual void startEngine() {}
	virtual void spriteAdd(const cocos2d::Vec2& location) {}

};

#endif