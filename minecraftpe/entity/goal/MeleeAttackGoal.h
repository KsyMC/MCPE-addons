#pragma once

#include "Goal.h"

// Size : 64
class MeleeAttackGoal : public Goal
{
public:
	MeleeAttackGoal(Mob *, float, bool);
	virtual ~MeleeAttackGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
	virtual void stop();
	virtual void tick();
	virtual void getAttackReachSqr();
};
