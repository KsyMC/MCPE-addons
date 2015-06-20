#pragma once

class Mouse
{
public:
	static Mouse _instance;

public:
	static void feed(char, char, short, short);
	static void feed(char, char, short, short, short, short);
	static void getButtonState(int);
	static float getDX();
	static float getDY();
	static void getEvent();
	static void getEventButton();
	static void getEventButtonState();
	static int getX();
	static int getY();
	static bool isButtonDown(int);
	static void next();
	static void reset();
	static void reset2();
	static void rewind();
};
