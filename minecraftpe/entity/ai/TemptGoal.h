#pragma once

#include "Goal.h"

class PathfinderMob;

// Size : 96
class TemptGoal : public Goal
{
public:
	TemptGoal(PathfinderMob *, float);
	TemptGoal(PathfinderMob *, float, short, short, short);
	virtual ~TemptGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
	virtual void stop();
	virtual void tick();
};
