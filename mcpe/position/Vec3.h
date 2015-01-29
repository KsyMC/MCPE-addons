#ifndef __VEC3_H__
#define __VEC3_H__

struct TilePos;

typedef struct Vec3 {
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

	int _x;		// 0
	int _y;		// 4
	int _z;		// 8

	Vec3(const TilePos &);
} VEC3;

#endif
