#include "SceneMain.h"
#include "core/LayerEntity.h"
#include "ui/menu/LayerMenuStart.h"

USING_NS_CC;

SceneMain::SceneMain()
{
}

SceneMain::~SceneMain()
{
}


bool SceneMain::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Scene::init());

		auto layerEntity = LayerEntity::create();
		addChild(layerEntity);

		auto layerMenuStart = LayerMenuStart::create();
		addChild(layerMenuStart);

		isInit = true;
	} while (0);

	return isInit;
}
