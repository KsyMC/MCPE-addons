#pragma once

#include "Goal.h"

// Size : 56
class MountPathingGoal : public Goal
{
public:
	MountPathingGoal(Mob *, float, float, bool);
	virtual ~MountPathingGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
	virtual void stop();
	virtual void tick();
	virtual void getAttackReachSqr();
};
