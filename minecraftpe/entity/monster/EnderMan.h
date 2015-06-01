#pragma once

#include "Monster.h"

class FullTile;

// Size : 3232
class EnderMan : public Monster
{
public:
	EnderMan(TileSource &);
	virtual ~EnderMan();
	virtual void normalTick();
	virtual void hurt(EntityDamageSource &, int);
	virtual int getEntityTypeId() const;
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual float getBaseSpeed();
	virtual int getMaxHealth();
	virtual void aiStep();
	virtual Item *getDeathLoot();
	virtual void newServerAiStep();
	virtual const char *getAmbientSound();
	virtual std::string getHurtSound();
	virtual std::string getDeathSound();
	virtual bool useNewAi();
	void getCarryingBlock();
	bool isCreepy();
	bool isLookingAtMe(Player *);
	void setCarryingBlock(FullTile);
	void setCreepy(bool);
	void teleport(float, float, float);
	void teleport();
	void teleportTowards(Entity *);
};
