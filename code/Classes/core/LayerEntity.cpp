#include "LayerEntity.h"

USING_NS_CC;

LayerEntity::LayerEntity()
{
}

LayerEntity::~LayerEntity()
{
}

bool LayerEntity::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		isInit = true;
	} while (0);

	return isInit;
}
