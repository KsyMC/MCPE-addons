#pragma once

#include "DoorInteractGoal.h"

// Size : 44
class BreakDoorGoal : public DoorInteractGoal
{
public:
	BreakDoorGoal(Mob *);
	virtual ~BreakDoorGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
	virtual void tick();
};
