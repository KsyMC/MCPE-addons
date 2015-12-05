#pragma once

#include <vector>
#include <string>

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
	void areAllEffectsAmbient(const std::vector<MobEffectInstance *> &);
	bool equals(MobEffectInstance *) const;
	void getColorValue(const std::vector<MobEffectInstance *> &);
	std::string getDescriptionId() const;
	std::string getDisplayName() const;
	bool isNoCounter() const;
	void load(CompoundTag *);
	void save() const;
	void setNoCounter(bool);
	void tick(Mob *);
	std::string toString() const;
	void update(const MobEffectInstance &);
};
