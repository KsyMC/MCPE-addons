#pragma once

#include "MouseDevice.h"

class Multitouch
{
public:
	static int _activePointerCount;
	static int _activePointerList[];
	static int _activePointerThisUpdateCount;
	static int _activePointerThisUpdateList[];
	static int _index;
	static void *_inputs;
	static MouseDevice _pointers[];
	static void *_wasEdgeTouch;
	static void *_wasPressed;
	static void *_wasPressedThisUpdate;
	static void *_wasReleased;
	static void *_wasReleasedThisUpdate;

public:
	static void commit();
	static void feed(char, char, short, short, char);
	static int getActivePointerIds(const int **);
	static int getActivePointerIdsThisUpdate(const int **);
	static void getFirstActivePointerIdEx();
	static void getFirstActivePointerIdExThisUpdate();
	static bool isEdgeTouch(int);
	static bool isPointerDown(int);
	static bool isPressed(int);
	static bool isPressedThisUpdate(int);
	static bool isReleased(int);
	static void isReleasedThisUpdate(int);
	static void next();
	static void reset();
	static void resetThisUpdate();
};
