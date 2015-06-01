#pragma once

class TilePos;

class Vec3
{
public:
	static const Vec3 MAX;
	static const Vec3 MIN;
	static const Vec3 NEG_UNIT_X;
	static const Vec3 NEG_UNIT_Y;
	static const Vec3 NEG_UNIT_Z;
	static const Vec3 ONE;
	static const Vec3 UINT_X;
	static const Vec3 UINT_Y;
	static const Vec3 UINT_Z;
	static const Vec3 ZERO;

public:
	float x;	// 0
	float y;	// 4
	float z;	// 8

public:
	Vec3(const TilePos &);
};