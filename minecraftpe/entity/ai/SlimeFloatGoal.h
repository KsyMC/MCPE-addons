#pragma once

#include "Goal.h"

// Size : 16
class SlimeFloatGoal : public Goal
{
public:
	virtual ~SlimeFloatGoal();
	virtual bool canUse();
	virtual void tick();
};
