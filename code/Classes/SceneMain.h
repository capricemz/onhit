#ifndef __SCENE_MAIN_H__
#define __SCENE_MAIN_H__

#include "cocos2d.h"
#include "ISceneMain.h"
#include "HandleSceneMain.h"
#include "ui/menu/LayerMenuStart.h"

class SceneMain : public cocos2d::Scene, ISceneMain
{
public:
	CREATE_FUNC(SceneMain);

	SceneMain();
	~SceneMain();

	virtual bool init();

	virtual void layerMenuStartAdd();
	virtual void layerMenuStartRemove();

private:
	LayerMenuStart* _layerMenuStart;
	HandleSceneMain* _handleSceneMain;

};

#endif
