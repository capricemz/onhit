#ifndef __HANDLE_SCENE_MAIN__
#define __HANDLE_SCENE_MAIN__

#include "cocos2d.h"
#include "ISceneMain.h"
#include "common/observer/Observer.h"

class HandleSceneMain : public cocos2d::Ref, Observer
{
public:
	CREATE_FUNC(HandleSceneMain);

	HandleSceneMain();
	~HandleSceneMain();

	virtual bool init();
	virtual void updateBySubject(va_list values);

	CC_SYNTHESIZE(ISceneMain*, _sceneMain, SceneMain);

private:
	
};

#endif