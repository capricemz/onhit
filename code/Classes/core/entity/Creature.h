#ifndef __CORE_ENTITY_CREATURE_H__
#define __CORE_ENTITY_CREATURE_H__

#include "Unit.h"

class Creature : public Unit
{
public:
	CREATE_FUNC(Creature);

	Creature();
	~Creature();

	virtual bool init();

private:

};

#endif