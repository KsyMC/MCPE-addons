#pragma once

#include "shared.h"

class Mob;
class CompoundTag;

// Size : 16
class MobEffectInstance
{
public:
	MobEffectInstance(int);
	MobEffectInstance(int, int);
	MobEffectInstance(int, int, int);
	MobEffectInstance(int, int, int, bool, bool);
	void applyEffect(Mob *);
	void areAllEffectsAmbient(const vector<MobEffectInstance *> &);
	bool equals(MobEffectInstance *) const;
	void getColorValue(const vector<MobEffectInstance *> &);
	string getDescriptionId() const;
	string getDisplayName() const;
	bool isNoCounter() const;
	void load(CompoundTag *);
	void save() const;
	void setNoCounter(bool);
	void tick(Mob *);
	string toString() const;
	void update(const MobEffectInstance &);
};
