#ifndef __CORE_ENTITY_HANDLE_ENTITY_H__
#define __CORE_ENTITY_HANDLE_ENTITY_H__

#include "cocos2d.h"
#include "ILayerEntity.h"
#include "common/observer/Observer.h"

class HandleEntity : public cocos2d::Ref, Observer
{
public:
	CREATE_FUNC(HandleEntity);

	HandleEntity();
	~HandleEntity();

	void entityAdd(const cocos2d::Vec2& location);

	virtual bool init();
	virtual void updateBySubject(va_list values);

	/*ILayerEntity* getLayerEntity() const { return _layerEntity; }
	void setLayerEntity(ILayerEntity* val) { _layerEntity = val; }*/
	CC_SYNTHESIZE(ILayerEntity*, _layerEntity, LayerEntity);

private:
	/*ILayerEntity* _layerEntity;*/
};

#endif