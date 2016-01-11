#pragma once

#include <vector>

#include "minecraftpe/block/FullBlock.h"
#include "minecraftpe/entity/EntityType.h"
#include "minecraftpe/level/dimension/DimensionId.h"

class Level;
class Block;
class Dimension;
class AABB;
class Entity;
class BlockEntity;

// Size : 68
class BlockSource
{
public:
	FullBlock getBlockAndData(const BlockPos &);
	void setBlockAndData(const BlockPos &, FullBlock, int update);
	void setBlockAndDataNoUpdate(int x, int y, int z, FullBlock);

	Block *getBlock(int, int, int);
	Block *getBlock(const BlockPos &);
	BlockID getBlockID(const BlockPos &);
	BlockEntity *getBlockEntity(const BlockPos &);

	Dimension *getDimension();
	Dimension *getDimension() const;
	Dimension *getDimensionConst() const;
	DimensionId getDimensionId() const;

	Level *getLevel();
	Level *getLevel() const;
	Level *getLevelConst() const;

	std::vector<Entity *> &getEntities(EntityType, const AABB &, Entity *);
};
