#pragma once

#include "Goal.h"

class PathfinderMob;

// Size : 72
class AvoidMobTypeGoal : public Goal
{
public:
	AvoidMobTypeGoal(PathfinderMob *, int, float, float, float);
	virtual ~AvoidMobTypeGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
	virtual void stop();
	virtual void tick();
};
