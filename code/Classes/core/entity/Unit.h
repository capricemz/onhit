#ifndef __CORE_ENTITY_UNIT_H__
#define __CORE_ENTITY_UNIT_H__

#include "Entity.h"

class Unit : public Entity
{
public:
	CREATE_FUNC(Unit);

	Unit();
	~Unit();

	virtual bool init();

private:

};

#endif