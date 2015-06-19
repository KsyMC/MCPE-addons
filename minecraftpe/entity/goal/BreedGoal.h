#pragma once

#include "Goal.h"

class Animal;

// Size : 48
class BreedGoal : public Goal
{
public:
	BreedGoal(Animal *, float);
	virtual ~BreedGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void stop();
	virtual void tick();
};
