#pragma once

#include "Goal.h"

class Creeper;

// Size : 40
class SwellGoal : public Goal
{
public:
	SwellGoal(Creeper *);
	virtual ~SwellGoal();
	virtual bool canUse();
	virtual void start();
	virtual void stop();
	virtual void tick();
};
