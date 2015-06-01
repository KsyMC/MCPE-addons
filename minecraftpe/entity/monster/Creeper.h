#pragma once

#include "Monster.h"

class Creeper : public Monster
{
public:
	Creeper(TileSource &);
	virtual ~Creeper();
	virtual void normalTick();
	virtual void interactWithPlayer(Player *);
	virtual bool canInteractWith(Player *);
	virtual std::string getInteractText(Player *);
	virtual int getEntityTypeId() const;
	virtual float getBaseSpeed();
	virtual int getMaxHealth();
	virtual Item *getDeathLoot();
	virtual std::string getDeathSound();
	virtual bool useNewAi();
	virtual void checkHurtTarget(Entity *, float);
	virtual void checkCantSeeTarget(Entity *, float);
	void setSwellDir(int);
	void getSwellDir();
	void getSwelling(float) const;
};