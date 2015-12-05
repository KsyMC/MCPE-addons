#pragma once

#include "../AgableMob.h"

class WaterAnimal : public AgableMob
{
public:
	WaterAnimal(BlockSource &);
	virtual ~WaterAnimal();
	virtual void normalTick();
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void isWaterMob();
	virtual void getAmbientSoundInterval();
	virtual void getBaseSpeed();
	virtual void canSpawn();
	virtual void removeWhenFarAway();
	void getExperienceReward(Player *);
};
