#pragma once

#include "Block.h"

// Size : 144
class TransparentBlock : public Block
{
public:
	bool b1;	// 140

public:
	TransparentBlock(std::string const &, int, std::string const &, Material const &, bool);
	virtual ~TransparentBlock();
	virtual void shouldRenderFace(BlockSource &, BlockPos const &, signed char, AABB const &) const;
};
