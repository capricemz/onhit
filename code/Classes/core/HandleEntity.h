#ifndef __CORE_HANDLE_ENTITY_H__
#define __CORE_HANDLE_ENTITY_H__

#include "cocos2d.h"
#include "ILayerEntity.h"

class HandleEntity : public cocos2d::Ref
{
public:
	CREATE_FUNC(HandleEntity);

	HandleEntity();
	~HandleEntity();

	virtual bool init();

	ILayerEntity * getLayerEntity() const { return _layerEntity; }
	void setLayerEntity(ILayerEntity * val) { _layerEntity = val; }

private:
	ILayerEntity *_layerEntity;
};

#endif