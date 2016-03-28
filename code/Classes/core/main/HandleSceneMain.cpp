#include "HandleSceneMain.h"
#include "core/ManagerHandle.h"
#include "model/define/DfinesValue.h"

USING_NS_CC;

HandleSceneMain::HandleSceneMain() : _sceneMain(nullptr)
{
}

HandleSceneMain::~HandleSceneMain()
{
	ManagerHandle::getInstance()->detach(this);

	_sceneMain = nullptr;
}

bool HandleSceneMain::init()
{
	auto isInit = false;

	do
	{
		idObserverSet((int)ID_OBSERVER::HANDLE_SCENE_MAIN);
		ManagerHandle::getInstance()->attach(this);

		isInit = true;
	} while (0);

	return isInit;
}

void HandleSceneMain::updateBySubject(va_list values)
{
	auto type = va_arg(values, TYPE_OBSERVER_HANDLE_SCENE_MAIN);
	switch (type)
	{
	case TYPE_OBSERVER_HANDLE_SCENE_MAIN::LAYER_MENU_START_ADD:
		_sceneMain->layerMenuStartAdd();
		break;
	case TYPE_OBSERVER_HANDLE_SCENE_MAIN::LAYER_MENU_START_REMOVE:
		_sceneMain->layerMenuStartRemove();
		break;
	default:
		break;
	}
}
