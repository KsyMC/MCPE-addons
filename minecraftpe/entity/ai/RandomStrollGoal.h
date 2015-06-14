#pragma once

#include "Goal.h"

class PathfinderMob;

// Size : 28
class RandomStrollGoal : public Goal
{
public:
	RandomStrollGoal(PathfinderMob *, float);
	virtual ~RandomStrollGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
};
