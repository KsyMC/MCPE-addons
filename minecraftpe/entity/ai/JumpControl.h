#pragma once

// Size : 12
class JumpControl
{
public:
	JumpControl(Mob *);
	virtual void tick();
	virtual ~JumpControl();
};
