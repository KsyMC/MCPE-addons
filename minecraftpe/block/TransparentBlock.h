#pragma once

#include <minecraftpe/block/Block.h>

// Size : 144
class TransparentTile : public Block
{
public:
	bool b1;	// 140

public:
	virtual ~TransparentTile();
	virtual void shouldRenderFace(BlockSource *, int, int, int, signed char, const AABB &) const;
};