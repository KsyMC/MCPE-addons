#pragma once

#include "Zombie.h"

// Size : 3264
class PigZombie : public Zombie
{
public:
	PigZombie(TileSource &);
	virtual ~PigZombie();
	virtual void normalTick();
	virtual void interactWithPlayer(Player *);
	virtual void hurt(EntityDamageSource &, int);
	virtual int getEntityTypeId() const;
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void *getTexture();
	virtual float getBaseSpeed();
	virtual bool canSpawn();
	virtual Item *getCarriedItem();
	virtual Item *getDeathLoot();
	virtual void dropDeathLoot();
	virtual const char *getAmbientSound();
	virtual std::string getHurtSound();
	virtual std::string getDeathSound();
	virtual bool useNewAi();
	virtual void findAttackTarget();
	virtual int getAttackTime();
};
