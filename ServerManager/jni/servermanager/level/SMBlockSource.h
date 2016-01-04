#pragma once

class SMEntity;
class Vec3;
class ItemInstance;
class BlockSource;

class SMBlockSource
{
private:
	SMEntity *entity;

public:
	SMBlockSource(SMEntity *entity);

	void dropItem(const Vec3 &pos, const ItemInstance &item, int pickupDelay);

	BlockSource *getHandle() const;
};
