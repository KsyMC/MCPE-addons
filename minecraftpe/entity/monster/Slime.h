#pragma once

#include "Monster.h"

class Slime : public Monster
{
public:
	Slime(TileSource &);
	virtual ~Slime();
	virtual void remove();
	virtual void normalTick();
	virtual float getShadowRadius() const;
	virtual void playerTouch(Player *);
	virtual int getEntityTypeId() const;
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void onSynchedDataUpdate(int);
	virtual float getBaseSpeed();
	virtual int getMaxHealth();
	virtual void aiStep();
	virtual bool canSpawn();
	virtual void finalizeMobSpawn();
	virtual Item *getDeathLoot();
	virtual std::string getHurtSound();
	virtual std::string getDeathSound();
	virtual bool useNewAi();
	virtual void findAttackTarget();
	virtual void getJumpDelay();
	virtual void doPlayJumpSound();
	virtual void playJumpSound();
	virtual void getSquishSound();
	virtual bool isDealsDamage();
	virtual void decreaseSquish();
	virtual void createChild(int);
	float getModelScale();
	int getSlimeSize() const;
	bool makeStepSound();
	void setSlimeSize(int);
};
