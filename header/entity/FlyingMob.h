#pragma once

#include "Mob.h"

// Size : 3178
class FlyingMob : public Mob
{
public:
	FlyingMob(BlockSource &);
	virtual ~FlyingMob();
	virtual void causeFallDamage(float);
	virtual void onLadder();
	virtual void travel(float, float);
};
