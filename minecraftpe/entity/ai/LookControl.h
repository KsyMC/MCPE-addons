#pragma once

// Size : 32
class LookControl
{
public:
	LookControl(Mob *);
	virtual void tick();
	virtual ~LookControl();
	void setLookAt(Entity *, float, float);
	void setLookAt(float, float, float, float, float);
};
