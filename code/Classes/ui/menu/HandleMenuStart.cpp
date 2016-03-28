#include "HandleMenuStart.h"
#include "model/define/DfinesValue.h"
#include "core/ManagerHandle.h"

HandleMenuStart::HandleMenuStart() : _layerMenuStart(nullptr)
{
}

HandleMenuStart::~HandleMenuStart()
{
	_layerMenuStart = nullptr;
}

void HandleMenuStart::gameStart()
{
	auto managerUI = ManagerHandle::getInstance();
	managerUI->notify((int)ID_OBSERVER::HANDLE_LAYER_ENTITY, TYPE_OBSERVER_HANDLE_ENTITY::LAYER_ENTITY_START_ENGINE);
	managerUI->notify((int)ID_OBSERVER::HANDLE_SCENE_MAIN, TYPE_OBSERVER_HANDLE_SCENE_MAIN::LAYER_MENU_START_REMOVE);
}

void HandleMenuStart::gameSaveLoad()
{

}

void HandleMenuStart::gameSetting()
{

}

bool HandleMenuStart::init()
{
	auto isInit = false;

	do 
	{
		isInit = true;
	} while (0);

	return isInit;
}
