#pragma once

#include "Block.h"

// Size : 140
class EntityBlock : public Block
{
public:
	EntityBlock(std::string const &, int, Material const &);
	EntityBlock(std::string const &, int, std::string const &, Material const &);
	virtual ~EntityBlock();
	virtual void neighborChanged(BlockSource &, BlockPos const &, BlockPos const &);
	virtual void triggerEvent(BlockSource &, BlockPos const &, int, int);
};
