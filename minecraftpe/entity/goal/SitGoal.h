#pragma once

#include "Goal.h"

// Size : 20
class SitGoal : public Goal
{
public:
	virtual ~SitGoal();
	virtual bool canUse();
	virtual void start();
	virtual void stop();
};
