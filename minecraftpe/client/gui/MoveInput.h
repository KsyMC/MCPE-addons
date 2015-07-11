#pragma once

class Player;
class Config;

class MoveInput
{
public:
	//void **vtable;			// 0
	float moveX;				// 4
	float moveY;				// 8
	bool sneaking;				// 12
	bool up;					// 13
	bool down;					// 14
	bool upDown;				// 15
	bool jumping;				// 16
	bool b5;					// 17

public:
	virtual ~MoveInput();
	virtual void tick(Player &);
	virtual void render(float);
	virtual void setKey(int, bool);
	virtual void releaseAllKeys();
	virtual void onConfigChanged(const Config &);
	virtual void allowPicking(float, float);
	virtual void setJumping(bool);
};
