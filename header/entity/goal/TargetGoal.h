#pragma once

#include "Goal.h"

class TargetGoal : public Goal
{
public:
	virtual ~TargetGoal();
	virtual bool canContinueToUse();
	virtual void stop();
};
