#pragma once

#include "TamableAnimal.h"

class Wolf : public TamableAnimal
{
public:
	Wolf(BlockSource &);
	virtual ~Wolf();
	virtual int getCollarColor() const;
	virtual void setCollarColor(int);
	virtual bool isAngry() const;
	virtual float getHeadRollAngle(float);
	virtual float getBodyRollAngle(float, float);
	virtual float getBaseSpeed();
	virtual int getEntityTypeId() const;
	virtual bool doHurtTarget(Entity *);
	virtual bool shouldDespawn() const;
	virtual std::string getHurtSound(); // protected?
	virtual std::string getDeathSound(); // protected?
	virtual bool isFood(const ItemInstance *) const;
	virtual bool canInteractWith(Player *);
	virtual float getWetShade(float);
	virtual bool isWet() const;
	virtual void setWet(bool);
	virtual const char *getAmbientSound();
	virtual std::string &getTexture();
	virtual std::string getInteractText(Player *);
	virtual bool isInterested() const;
	virtual void setAngry(bool);
	virtual void setInterested(bool);
	virtual Animal *getBreedOffspring(Animal *);
};
