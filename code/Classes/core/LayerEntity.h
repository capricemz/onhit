#ifndef __CORE_LAYER_ENTITY_H__
#define __CORE_LAYER_ENTITY_H__

#include "cocos2d.h"
#include "ILayerEntity.h"
#include "HandleEntity.h"

class LayerEntity : public cocos2d::Layer, ILayerEntity
{
public:
	CREATE_FUNC(LayerEntity);

	LayerEntity();
	~LayerEntity();

	virtual bool init();

private:
	HandleEntity *_handleEntity;

};

#endif