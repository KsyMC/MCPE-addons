#pragma once

#include "Goal.h"

class Animal;

// Size : 48
class FollowParentGoal : public Goal
{
public:
	FollowParentGoal(Animal *, float);
	virtual ~FollowParentGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
	virtual void stop();
	virtual void tick();
};
