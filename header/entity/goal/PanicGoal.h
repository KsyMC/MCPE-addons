#pragma once

#include "Goal.h"

class PathfinderMob;

// Size : 28
class PanicGoal : public Goal
{
public:
	PanicGoal(PathfinderMob *, float);
	virtual ~PanicGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
};
