#pragma once

// Size : 28
class MoveControl
{
public:
	static float MAX_TURN;
	static float MIN_SPEED;

public:
	//void **vtable;	// 0
	Mob *mob;			// 4
	float posX;			// 8
	float posY;			// 12
	float posZ;			// 16
	float speed;		// 20
	bool update;		// 24

public:
	MoveControl(Mob *);
	virtual ~MoveControl();
	virtual void tick();
	float getSpeed();
	void hasWanted();
	void setWantedPosition(float, float, float, float);
};
