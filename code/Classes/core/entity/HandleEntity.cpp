#include "HandleEntity.h"
#include "ui/ManagerUI.h"
#include "model/define/DfinesValue.h"

USING_NS_CC;

HandleEntity::HandleEntity() : _layerEntity(nullptr)
{
}

HandleEntity::~HandleEntity()
{
	ManagerUI::getInstance()->detach(this);

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
		ManagerUI::getInstance()->attach(this);

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
		getLayerEntity()->startEngine();
		break;
	default:
		break;
	}
}
