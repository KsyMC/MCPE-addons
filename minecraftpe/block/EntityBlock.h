#pragma once

#include <minecraftpe/block/Block.h>

class BlockEntity;

// Size : 140
class EntityTile : public Block
{
public:
	EntityTile(int, const Material *);
	EntityTile(int, const std::string &, const Material *);
	virtual ~EntityTile();
	virtual void neighborChanged(BlockSource *, int, int, int, int, int, int);
	virtual void triggerEvent(BlockSource *, int, int, int, int, int);
	virtual BlockEntity *newTileEntity(const BlockPos &);
};