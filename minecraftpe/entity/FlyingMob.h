#pragma once

#include "Mob.h"

// Size : 3178
class FlyingMob : public Mob
{
public:
	FlyingMob(TileSource &);
	virtual ~FlyingMob();
	virtual void causeFallDamage(float);
	virtual void onLadder();
	virtual void travel(float, float);
};
