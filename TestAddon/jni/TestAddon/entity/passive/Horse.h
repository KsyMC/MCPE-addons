#pragma once

#include "minecraftpe/entity/passive/Animal.h"

class Horse : public Animal
{
public:
	char filler1[16]; // 3224

public:
	Horse(TileSource &);
	virtual ~Horse();
	virtual int getEntityTypeId() const;
	virtual float getBaseSpeed();
	virtual int getMaxHealth();
	virtual int getDeathLoot();
	virtual std::string getHurtSound();
	virtual std::string getDeathSound();
	virtual Entity *getBreedOffspring(Animal *);
};
