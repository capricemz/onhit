#include "SceneMain.h"
#include "core/entity/LayerEntity.h"

USING_NS_CC;

SceneMain::SceneMain() : _layerMenuStart(nullptr), _handleSceneMain(nullptr)
{
}

SceneMain::~SceneMain()
{
	_layerMenuStart = nullptr;

	CC_SAFE_RELEASE_NULL(_handleSceneMain);
}


bool SceneMain::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Scene::init());

		auto layerEntity = LayerEntity::create();
		addChild(layerEntity);

		layerMenuStartAdd();

		_handleSceneMain = HandleSceneMain::create();
		_handleSceneMain->retain();
		_handleSceneMain->setSceneMain(this);

		isInit = true;
	} while (0);

	return isInit;
}

void SceneMain::layerMenuStartAdd()
{
	_layerMenuStart = LayerMenuStart::create();
	addChild(_layerMenuStart);
}

void SceneMain::layerMenuStartRemove()
{
	if (_layerMenuStart)
	{
		_layerMenuStart->removeFromParent();
		_layerMenuStart = nullptr;
	}
}
