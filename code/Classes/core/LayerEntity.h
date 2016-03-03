#ifndef _CORE_LAYER_ENTITY_H_
#define _CORE_LAYER_ENTITY_H_

#include "cocos2d.h"

class LayerEntity : public cocos2d::Layer
{
public:
	CREATE_FUNC(LayerEntity);

	LayerEntity();
	~LayerEntity();

	virtual bool init();

private:

};

#endif