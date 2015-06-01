#pragma once

#include "Animal.h"

class TamableAnimal :public Animal
{
public:
	TamableAnimal(TileSource &);
	virtual ~TamableAnimal();
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void isTamable() const;
	virtual void getOwner() const;
	virtual void setOwner(EntityUniqueID);
	virtual void isTame() const;
	virtual void isSitting() const;
	virtual void setSitting(bool);
	virtual void spawnTamingParticles(bool);
};
