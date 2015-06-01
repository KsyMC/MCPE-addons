#pragma once

#include "monster\Mob.h"

// Size : 3204
class PathfinderMob : public Mob
{
public:
	static float MAX_TURN;

public:
	PathfinderMob(TileSource &);
	virtual ~PathfinderMob();
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void canSpawn();
	virtual void updateAi();
	virtual void getWalkingSpeedModifier();
	virtual void getAttackTarget();
	virtual void setAttackTarget(Entity *);
	virtual void getWalkTargetValue(const TilePos &);
	virtual void findAttackTarget();
	virtual void checkHurtTarget(Entity *, float);
	virtual void checkCantSeeTarget(Entity *, float);
	virtual void shouldHoldGround();
	virtual void findRandomStrollLocation();
	void getNoActionTime();
	bool isPathFinding();
};
