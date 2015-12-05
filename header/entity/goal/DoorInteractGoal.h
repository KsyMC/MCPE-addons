#pragma once

#include "Goal.h"

class DoorInteractGoal : public Goal
{
public:
	DoorInteractGoal(Mob *);
	virtual ~DoorInteractGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
	virtual void tick();
};
