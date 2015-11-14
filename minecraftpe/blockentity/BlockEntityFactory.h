#pragma once

#include "BlockEntityType.h"

class BlockEntity;
class BlockPos;

class BlockEntityFactory
{
public:
	static BlockEntity *createTileEntity(BlockEntityType, const BlockPos &);
};
