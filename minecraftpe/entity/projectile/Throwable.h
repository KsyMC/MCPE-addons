#pragma once

#include "../Entity.h"

class Throwable : public Entity
{
public:
	Throwable(TileSource &);
	virtual void ~Throwable();
	virtual void lerpMotion(float, float, float);
	virtual void normalTick();
	virtual void getShadowHeightOffs();
	virtual void shouldRenderAtSqrDistance(float);
	virtual void getOwnerID();
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void getThrowPower();
	virtual void getThrowUpAngleOffset();
	virtual void getGravity();
	virtual void onHit(const HitResult &) = 0;
};
