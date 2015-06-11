#pragma once

#include "../PathfinderMob.h"

// Size : 3224
class Monster : public PathfinderMob
{
public:
	char filler1[20]; // 3204

public:
	Monster(TileSource &);
	virtual ~Monster();
	virtual void normalTick();
	virtual bool isSurfaceMob() const;
	virtual void hurt(EntityDamageSource &, int);
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag*);
	virtual void aiStep();
	virtual bool canSpawn();
	virtual void shouldDespawn() const;
	virtual void doHurtTarget(Entity *);
	virtual void getWalkTargetValue(const TilePos &);
	virtual void findAttackTarget();
	virtual void checkHurtTarget(Entity *, float);
	virtual void getAttackDamage(Entity *);
	virtual void getAttackTime();
	void setNightly();
};
