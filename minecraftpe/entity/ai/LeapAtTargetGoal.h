#pragma once

#include "Goal.h"

// Size : 48
class LeapAtTargetGoal : public Goal
{
public:
	LeapAtTargetGoal(Mob *, float);
	virtual ~LeapAtTargetGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
};
