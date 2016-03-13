#ifndef __UI_MANAGER_UI_H__
#define __UI_MANAGER_UI_H__

#include "cocos2d.h"
#include "common/observer/Observer.h"

class ManagerUI : public Subject
{
public:
	static ManagerUI *getInstance();//提供getInstance全局指针
	static void destroyInstance();

	~ManagerUI();

private:
	ManagerUI();

};

#endif