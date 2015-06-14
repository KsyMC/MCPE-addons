#pragma once

#include "LookAtMobGoal.h"

// Size : 56
class InteractGoal : public LookAtMobGoal
{
public:
	InteractGoal(Mob *, float, int);
	InteractGoal(Mob *, float, int, float);
	virtual ~InteractGoal();
};
