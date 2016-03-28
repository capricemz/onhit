#include "ManagerHandle.h"

USING_NS_CC;

static ManagerHandle *_instance;

ManagerHandle * ManagerHandle::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new ManagerHandle();
	}
	return _instance;
}

void ManagerHandle::destroyInstance()
{
	CC_SAFE_DELETE(_instance);
}

ManagerHandle::ManagerHandle()
{
}

ManagerHandle::~ManagerHandle()
{
}
