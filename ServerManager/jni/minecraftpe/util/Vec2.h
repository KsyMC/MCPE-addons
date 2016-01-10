#pragma once

// Size : 8
class Vec2
{
public:
	static Vec2 ZERO;
	static Vec2 MAX;
	static Vec2 MIN;
	static Vec2 ONE;

	float x;	// 0
	float y;	// 4

	Vec2() : x(0), y(0) {};
	Vec2(float x, float y) : x(x), y(y) {};
};
