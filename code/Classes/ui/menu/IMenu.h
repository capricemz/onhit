#ifndef _UI_MENU_IMENU_H_
#define _UI_MENU_IMENU_H_

#include "cocos2d.h"

class ILayerMenuStart
{
public:
	virtual cocos2d::Layer * getSkin() { return nullptr; }
};

#endif