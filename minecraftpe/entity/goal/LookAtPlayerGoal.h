#pragma once

#include "Goal.h"

class LookAtPlayerGoal : public Goal
{
public:
	LookAtPlayerGoal(Mob *, float);
	LookAtPlayerGoal(Mob *, float, float);
	virtual ~LookAtPlayerGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
	virtual void stop();
	virtual void tick();
};
