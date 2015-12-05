#pragma once

class MouseDevice
{
public:
	short x;	// 4
	short y;	// 6

public:
	MouseDevice();
	~MouseDevice();
	void feed(char, char, short, short);
	void feed(char, char, short, short, short, short);
	void getButtonState(int);
	void getDX();
	void getDY();
	void getEvent();
	void getEventButton();
	void getEventButtonState();
	short getX();
	short getY();
	bool isButtonDown(int);
	void next();
	void reset();
	void reset2();
	void rewind();
	void wasFirstMovement();
};
