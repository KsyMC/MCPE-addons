#pragma once

#include "WaterAnimal.h"

class Squid : public WaterAnimal
{
public:
	Squid(TileSource &);
	virtual ~Squid();
	virtual void normalTick();
	virtual void hurt(EntityDamageSource &, int);
	virtual void handleEntityEvent(char);
	virtual int getEntityTypeId() const;
	virtual void getJumpPower() const;
	virtual int getMaxHealth();
	virtual void travel(float, float);
	virtual void aiStep();
	virtual bool canSpawn();
	virtual Item *getDeathLoot();
	virtual void dropDeathLoot();
	virtual float getSoundVolume();
	virtual const char *getAmbientSound();
	virtual std::string getHurtSound();
	virtual std::string getDeathSound();
};