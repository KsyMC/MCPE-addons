#pragma once

#include "..\AgableMob.h"

// Size : 3220
class Animal : public AgableMob
{
public:
	Animal(TileSource &);
	virtual ~Animal();
	virtual void interactWithPlayer(Player *);
	virtual void hurt(EntityDamageSource &, int);
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void getAmbientSoundInterval();
	virtual void aiStep();
	virtual void shouldDespawn() const;
	virtual void removeWhenFarAway();
	virtual void getWalkTargetValue(const TilePos &);
	virtual void findAttackTarget();
	virtual void canMate(const Animal *) const;
	virtual void isFood(const ItemInstance *) const;
	virtual void getBreedOffspring(Animal *) = 0;
	void _randomHeartPos();
	bool isInLove();
	void resetLove();
};
