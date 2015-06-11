#pragma once

#include "../FlyingMob.h"

// Size : 3240
class Ghast : public FlyingMob
{
public:
	Ghast(TileSource &);
	virtual ~Ghast();
	virtual void hurt(EntityDamageSource &, int);
	virtual int getEntityTypeId() const;
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void *getTexture();
	virtual float getBaseSpeed();
	virtual bool canSpawn();
	virtual Item *getDeathLoot();
	virtual void dropDeathLoot();
	virtual void newServerAiStep();
	virtual float getSoundVolume();
	virtual const char *getAmbientSound();
	virtual std::string getHurtSound();
	virtual std::string getDeathSound();
	virtual bool useNewAi();
	bool canReach(float, float, float, float);
	bool isCharging();
};
