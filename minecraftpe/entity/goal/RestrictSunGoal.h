#pragma once

#include "Goal.h"

class PathfinderMob;

// Size : 12
class RestrictSunGoal : public Goal
{
public:
	RestrictSunGoal(PathfinderMob *);
	virtual ~RestrictSunGoal();
	virtual bool canUse();
	virtual void start();
	virtual void stop();
};
