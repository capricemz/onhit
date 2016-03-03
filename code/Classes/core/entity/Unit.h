#ifndef _CORE_ENTITY_UNIT_H_
#define _CORE_ENTITY_UNIT_H_

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