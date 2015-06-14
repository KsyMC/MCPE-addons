#pragma once

#include "Goal.h"

class TamableAnimal;

// Size : 64
class FollowOwnerGoal : public Goal
{
public:
	FollowOwnerGoal(TamableAnimal *, float, float, float);
	virtual ~FollowOwnerGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
	virtual void stop();
	virtual void tick();
};
