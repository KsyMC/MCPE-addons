#pragma once

#include "Mob.h"

// Size : 3204
class PathfinderMob : public Mob
{
public:
	static float MAX_TURN;

public:
	char filler1[26]; // 3178

public:
	PathfinderMob(TileSource &);
	virtual ~PathfinderMob();
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual bool canSpawn();
	virtual void updateAi();
	virtual float getWalkingSpeedModifier();
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
