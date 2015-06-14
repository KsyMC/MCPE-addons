#pragma once

#include "Goal.h"

class PathfinderMob;

// Size : 28
class FleeSunGoal : public Goal
{
public:
	FleeSunGoal(PathfinderMob *, float);
	virtual ~FleeSunGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
};
