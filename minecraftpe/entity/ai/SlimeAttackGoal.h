#pragma once

#include "Goal.h"

// Size : 20
class SlimeAttackGoal : public Goal
{
public:
	virtual ~SlimeAttackGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
	virtual void tick();
};
