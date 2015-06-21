#pragma once

class TilePos;

class Vec3
{
public:
	static Vec3 MAX;
	static Vec3 MIN;
	static Vec3 NEG_UNIT_X;
	static Vec3 NEG_UNIT_Y;
	static Vec3 NEG_UNIT_Z;
	static Vec3 ONE;
	static Vec3 UINT_X;
	static Vec3 UINT_Y;
	static Vec3 UINT_Z;
	static Vec3 ZERO;

public:
	float x;	// 0
	float y;	// 4
	float z;	// 8

public:
	Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
	Vec3(const TilePos &);
};
