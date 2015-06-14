#pragma once

#include "LookAtPlayerGoal.h"

class LookAtMobGoal : public LookAtPlayerGoal
{
public:
	LookAtMobGoal(Mob *, float, int);
	LookAtMobGoal(Mob *, float, int, float);
	virtual ~LookAtMobGoal();
	virtual bool canUse();
};
