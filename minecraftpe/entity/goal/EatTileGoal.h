#pragma once

#include "Goal.h"

// Size : 16
class EatTileGoal : public Goal
{
public:
	EatTileGoal(Mob *);
	virtual ~EatTileGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
	virtual void stop();
	virtual void tick();
	virtual void getEatAnimationTick();
};
