#pragma once

#include "TargetGoal.h"

// Size : 20
class HurtByTargetGoal : public TargetGoal
{
public:
	HurtByTargetGoal(Mob *, bool);
	virtual ~HurtByTargetGoal();
	virtual bool canUse();
	virtual void start();
};
