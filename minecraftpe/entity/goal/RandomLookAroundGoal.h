#pragma once

#include "Goal.h"

// Size : 24
class RandomLookAroundGoal : public Goal
{
public:
	RandomLookAroundGoal(Mob *);
	virtual ~RandomLookAroundGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
	virtual void tick();
};
