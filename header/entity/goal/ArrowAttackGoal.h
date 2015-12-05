#pragma once

#include "Goal.h"

// Size : 64
class ArrowAttackGoal : public Goal
{
public:
	ArrowAttackGoal(Mob *, float, int, int);
	virtual ~ArrowAttackGoal();
	virtual bool canUse();
	virtual void canContinueToUse();
	virtual void stop();
	virtual void tick();
};
