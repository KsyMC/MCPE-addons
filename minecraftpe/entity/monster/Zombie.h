#pragma once

#include "Monster.h"

// Size : 3240
class Zombie : public Monster
{
public:
	Zombie(TileSource &);
	virtual ~Zombie();
	virtual int getEntityTypeId() const;
	virtual void setSize(float, float);
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void die(EntityDamageSource &);
	virtual float getBaseSpeed();
	virtual int getMaxHealth();
	virtual void getArmorValue();
	virtual void aiStep();
	virtual void finalizeMobSpawn();
	virtual bool isBaby() const;
	virtual int getDeathLoot();
	virtual const char *getAmbientSound();
	virtual std::string getHurtSound();
	virtual std::string getDeathSound();
	virtual bool useNewAi();
	virtual void getAttackDamage(Entity *);
	virtual void updateSize(bool);
};
