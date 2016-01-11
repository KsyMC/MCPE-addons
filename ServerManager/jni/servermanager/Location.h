#pragma once

#include "minecraftpe/util/Vec3.h"
#include "minecraftpe/util/Vec2.h"
#include "minecraftpe/block/FullBlock.h"

class SMBlockSource;

class Location
{
private:
	SMBlockSource *region;
	Vec3 position;
	Vec2 rotation;

public:
	Location();
	Location(SMBlockSource *region, const Vec3 &position, const Vec2 &rotation = {0, 0});

	void setRegion(SMBlockSource *region);
	SMBlockSource *getRegion() const;
	FullBlock getBlockAndData();

	void setPos(const Vec3 &position);
	void setX(float x);
	void setY(float y);
	void setZ(float z);

	const Vec3 &getPos() const;
	float getX();
	float getY();
	float getZ();

	void setRotation(const Vec2 &rotation);
	const Vec2 &getRotation() const;
};
