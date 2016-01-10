#pragma once

#include <string>

class Mob;

// Size : 32
class MobEffect
{
public:
	static MobEffect *ABSORPTION;
	static MobEffect *BLINDNESS;
	static MobEffect *CONFUSION;
	static MobEffect *DAMAGE_BOOST;
	static MobEffect *DAMAGE_RESISTANCE;
	static MobEffect *DIG_SLOWDOWN;
	static MobEffect *DIG_SPEED;
	static MobEffect *FIRE_RESISTANCE;
	static MobEffect *HARM;
	static MobEffect *HEAL;
	static MobEffect *HEALTH_BOOST;
	static MobEffect *HUNGER;
	static MobEffect *INVISIBILITY;
	static MobEffect *JUMP;
	static MobEffect *MOVEMENT_SLOWDOWN;
	static MobEffect *MOVEMENT_SPEED;
	static MobEffect *NIGHT_VISION;
	static MobEffect *POISON;
	static MobEffect *REGENERATION;
	static MobEffect *SATURATION;
	static MobEffect *WATER_BREATHING;
	static MobEffect *WEAKNESS;
	static MobEffect *WITHER;

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
