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
	float getX() const;
	float getY() const;
	float getZ() const;

	void setRotation(const Vec2 &rotation);
	void setYaw(float yaw);
	void setPitch(float pitch);

	const Vec2 &getRotation() const;
	float getYaw() const;
	float getPitch() const;

	bool equals(const Location &other) const;
};
