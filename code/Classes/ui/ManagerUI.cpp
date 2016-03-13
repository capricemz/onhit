#include "ManagerUI.h"

USING_NS_CC;

static ManagerUI *_instance;

ManagerUI * ManagerUI::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new ManagerUI();
	}
	return _instance;
}

void ManagerUI::destroyInstance()
{
	CC_SAFE_DELETE(_instance);
}

ManagerUI::ManagerUI()
{
}

ManagerUI::~ManagerUI()
{
}
