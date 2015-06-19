#pragma once

#include <string>

class Mob;

// Size : 32
class MobEffect
{
public:
	static MobEffect *absorption;
	static MobEffect *blindness;
	static MobEffect *damageBoost;
	static MobEffect *confusion;
	static MobEffect *damageResistance;
	static MobEffect *digSlowdown;
	static MobEffect *digSpeed;
	static MobEffect *fireResistance;
	static MobEffect *harm;
	static MobEffect *heal;
	static MobEffect *healthBoost;
	static MobEffect *hunger;
	static MobEffect *invisibility;
	static MobEffect *jump;
	static MobEffect *mobEffects;
	static MobEffect *movementSlowdown;
	static MobEffect *movementSpeed;
	static MobEffect *nightVision;
	static MobEffect *poison;
	static MobEffect *regeneration;
	static MobEffect *saturation;
	static MobEffect *waterBreathing;
	static MobEffect *weakness;
	static MobEffect *wither;

public:
	//void **vtable;	// 0
	int id;				// 4
	bool isBadEffect;	// 8
	int liquidColor;	// 12
	std::string name;	// 16
	int statusIconIndex;// 20
	float effectiveness;// 24
	bool usable;		// 28

public:
	MobEffect(int, const std::string &, bool, int, int);
	virtual ~MobEffect();
	virtual void applyEffectTick(Mob *, int) const;
	virtual void applyInstantenousEffect(Mob *, int, float) const;
	virtual bool isInstantenous() const;
	virtual bool isDurationEffectTick(int, int) const;
	int getColor() const;
	std::string getDescriptionId();
	void getDurationModifier() const;
	int getIcon() const;
	int getId() const;
	bool hasIcon() const;
	bool isDisabled() const;
	bool isHarmful() const;
	bool isInstantenous() const;
	static void initEffects();
	static std::string formatDuration(const MobEffectInstance *);
};
