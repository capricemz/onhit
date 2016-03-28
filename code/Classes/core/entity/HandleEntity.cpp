#include "HandleEntity.h"
#include "core/ManagerHandle.h"
#include "model/define/DfinesValue.h"

USING_NS_CC;

HandleEntity::HandleEntity() : _layerEntity(nullptr)
{
}

HandleEntity::~HandleEntity()
{
	ManagerHandle::getInstance()->detach(this);

	_layerEntity = nullptr;
}

void HandleEntity::entityAdd(const cocos2d::Vec2& location)
{
	_layerEntity->spriteAdd(location);
}

bool HandleEntity::init()
{
	auto isInit = false;

	do
	{
		idObserverSet((int)ID_OBSERVER::HANDLE_LAYER_ENTITY);
		ManagerHandle::getInstance()->attach(this);

		isInit = true;
	} while (0);

	return isInit;
}

void HandleEntity::updateBySubject(va_list values)
{
	auto type = va_arg(values, TYPE_OBSERVER_HANDLE_ENTITY);
	switch (type)
	{
	case TYPE_OBSERVER_HANDLE_ENTITY::LAYER_ENTITY_START_ENGINE:
		_layerEntity->startEngine();
		break;
	default:
		break;
	}
}
