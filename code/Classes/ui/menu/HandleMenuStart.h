#ifndef __UI_MENU_HADLE_MENU_START_H__
#define __UI_MENU_HADLE_MENU_START_H__

#include "cocos2d.h"
#include "IMenu.h"

class HandleMenuStart : public cocos2d::Ref
{
public:
	CREATE_FUNC(HandleMenuStart);

	HandleMenuStart();
	~HandleMenuStart();

	void gameStart();
	void gameSaveLoad();
	void gameSetting();

	virtual bool init();

	CC_SYNTHESIZE(ILayerMenuStart*, _layerMenuStart, LayerMenuStart);

private:
	
};

#endif