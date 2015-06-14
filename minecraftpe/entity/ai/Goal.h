#pragma once

class Mob;
class Level;
class TileSource;

// Size : 12
class Goal
{
public:
	//void **vtable;	// 0
	int mutexBits;		// 4
	Mob *theMob;		// 8

public:
	Goal(Mob *);
	virtual ~Goal();
	virtual bool canUse() = 0;
	virtual bool canContinueToUse();
	virtual bool canInterrupt();
	virtual void start();
	virtual void stop();
	virtual void tick();
	virtual void setRequiredControlFlags(int);
	virtual int getRequiredControlFlags();
	Level *getLevel();
	TileSource *getRegion();
};
