#ifndef __CORE_MANAGER_UI_H__
#define __CORE_MANAGER_UI_H__

#include "cocos2d.h"
#include "common/observer/Observer.h"

class ManagerHandle : public Subject
{
public:
	static ManagerHandle *getInstance();//�ṩgetInstanceȫ��ָ��
	static void destroyInstance();

	~ManagerHandle();

private:
	ManagerHandle();

};

#endif