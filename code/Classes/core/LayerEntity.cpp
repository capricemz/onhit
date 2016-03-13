#include "LayerEntity.h"

USING_NS_CC;

LayerEntity::LayerEntity() : _handleEntity(nullptr)
{
}

LayerEntity::~LayerEntity()
{
	CC_SAFE_RELEASE_NULL(_handleEntity);
}

bool LayerEntity::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_handleEntity = new HandleEntity();
		CC_SAFE_RETAIN(_handleEntity);
		_handleEntity->setLayerEntity(this);

		isInit = true;
	} while (0);

	return isInit;
}
