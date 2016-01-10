#pragma once

class CompoundTag;

// Size : 16
class Abilities
{
public:
	bool invulnerable;	// 0
	bool flying;		// 1
	bool mayfly;		// 2
	bool instabuild;	// 3
	bool what;			// 4
	bool lightning;		// 5
	float walkSpeed;	// 8
	float flySpeed;		// 12

	Abilities();
	void addSaveData(CompoundTag &) const;
	void loadSaveData(const CompoundTag &);
	float getFlyingSpeed() const;
	float getWalkingSpeed() const;
	void setFlyingSpeed(float);
	void setWalkingSpeed(float);
	bool isFlying() const;
};
