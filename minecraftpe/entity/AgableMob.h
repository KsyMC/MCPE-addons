#pragma once

#include "PathfinderMob.h"

// Size : 3216
class AgableMob : public PathfinderMob
{
public:
	int age;	// 3204
	char filler1[8]; // 3208

public:
	AgableMob(TileSource &);
	virtual ~AgableMob();
	virtual float getShadowRadius() const;
	virtual void setSize(float, float);
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void aiStep();
	virtual bool isBaby() const;
	int getAge();
	bool getAnimalFlag(int);
	void internalSetSize(float);
	void setAge(int);
	void setAnimalFlag(int, bool);
	void updateSize(bool);
};
