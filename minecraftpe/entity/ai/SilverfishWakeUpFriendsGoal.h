#pragma once

#include "Goal.h"

class Silverfish;

// Size : 20
class SilverfishWakeUpFriendsGoal : public Goal
{
public:
	SilverfishWakeUpFriendsGoal(Silverfish *);
	virtual ~SilverfishWakeUpFriendsGoal();
	virtual bool canUse();
	virtual void tick();
};
