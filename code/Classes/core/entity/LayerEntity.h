#ifndef __CORE_ENTITY_LAYER_ENTITY_H__
#define __CORE_ENTITY_LAYER_ENTITY_H__

#include "cocos2d.h"
#include "ILayerEntity.h"
#include "HandleEntity.h"
#include "HandleBox2d.h"

class LayerEntity : public cocos2d::Layer, ILayerEntity
{
public:
	CREATE_FUNC(LayerEntity);

	LayerEntity();
	~LayerEntity();

	virtual void startEngine();
	virtual void spriteAdd(const cocos2d::Vec2& location);

	virtual bool init();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void update(float dt);

private:
	HandleEntity* _handleEntity;
	HandleBox2d* _handleBox2d;

};

#endif