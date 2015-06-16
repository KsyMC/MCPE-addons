#pragma once

// Size : 5
class Abilities
{
public:
	bool invulnerable;	// 0
	bool flying;		// 1
	bool mayfly;		// 2
	bool instabuild;	// 3
	bool wtf;			// 4

public:
	Abilities();
	void addSaveData(void *);
	bool isFlying() const;
	void loadSaveData(void *);
};
