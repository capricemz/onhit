#include "HandleEntity.h"

HandleEntity::HandleEntity() : _layerEntity(nullptr)
{
}

HandleEntity::~HandleEntity()
{
	_layerEntity = nullptr;
}

bool HandleEntity::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}
