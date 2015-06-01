#pragma once

#include <string>

class Vec3;

// Size : 28
class AABB
{
public:
	static AABB EMPTY;
	static AABB MIN;

public:
	bool b1;		// 0
	float minX;		// 4
	float minY;		// 8
	float minZ;		// 12
	float maxX;		// 16
	float maxY;		// 20
	float maxZ;		// 24

public:
	AABB(const Vec3 &, const Vec3 &);
	AABB(const Vec3 &, float);
	AABB(float, float, float, float, float, float);
	AABB();
	void centerAt(const Vec3 &);
	void clip(const Vec3 &, const Vec3 &) const;
	void clipXCollide(const AABB &, float) const;
	void clipYCollide(const AABB &, float) const;
	void clipZCollide(const AABB &, float) const;
	void cloneMove(const Vec3 &) const;
	bool contains(const Vec3 &) const;
	void expand(const Vec3 &);
	void expanded(float, float, float);
	void flooredCeiledCopy() const;
	void flooredCopy(float, float) const;
	void getBounds() const;
	void getSize() const;
	void grow(const Vec3 &) const;
	void intersects(const AABB &) const;
	void intersectsInner(const AABB &) const;
	bool isEmpty() const;
	bool isNan() const;
	void merge(const AABB &) const;
	void move(float, float, float);
	void set(const AABB &);
	void set(const Vec3 &, const Vec3 &);
	void set(float, float, float, float, float, float);
	void shrink(const Vec3 &);
	std::string toString() const;
	void translated(const Vec3 &) const;
};