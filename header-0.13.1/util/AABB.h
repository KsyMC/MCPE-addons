#pragma once

#include "minecraftpe/util/Vec3.h"

// Size : 28
class AABB
{
public:
	static AABB EMPTY;

	Vec3 pos1;		// 0
	Vec3 pos2;		// 12
	bool empty;		// 24

	AABB();
	AABB(const Vec3 &, float);
	AABB(const Vec3 &, const Vec3 &);
	AABB(float x1, float y1, float z1, float x2, float y2, float z2);
	void move(const Vec3 &);
	void move(float x, float y, float z);
	void set(const AABB &);
	void set(const Vec3 &, const Vec3 &);
	void set(float x1, float y1, float z1, float x2, float y2, float z2);
	bool contains() const;
	bool isEmpty() const;
	bool isNan() const; // always false
	std::string toString() const;
};
