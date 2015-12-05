#pragma once

#include "Goal.h"

// Size : 48
class BegGoal : public Goal
{
public:
	virtual ~BegGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
	virtual void stop();
	virtual void tick();
};
