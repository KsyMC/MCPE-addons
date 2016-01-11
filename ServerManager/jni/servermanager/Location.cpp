#include <string>

#include "servermanager/Location.h"
#include "servermanager/level/SMBlockSource.h"
#include "minecraftpe/level/BlockSource.h"
#include "minecraftpe/block/BlockPos.h"

Location::Location()
{
	region = NULL;
}

Location::Location(SMBlockSource *region, const Vec3 &position, const Vec2 &rotation)
{
	this->region = region;
	this->position = position;
	this->rotation = rotation;
}

void Location::setRegion(SMBlockSource *region)
{
	this->region = region;
}

SMBlockSource *Location::getRegion() const
{
	return region;
}

FullBlock Location::getBlockAndData()
{
	return region->getHandle()->getBlockAndData(BlockPos(position));
}

void Location::setPos(const Vec3 &position)
{
	this->position = position;
}

void Location::setX(float x)
{
	position.x = x;
}

void Location::setY(float y)
{
	position.y = y;
}

void Location::setZ(float z)
{
	position.z = z;
}

const Vec3 &Location::getPos() const
{
	return position;
}

float Location::getX()
{
	return position.x;
}

float Location::getY()
{
	return position.y;
}

float Location::getZ()
{
	return position.z;
}

void Location::setRotation(const Vec2 &rotation)
{
	this->rotation = rotation;
}

const Vec2 &Location::getRotation() const
{
	return rotation;
}
