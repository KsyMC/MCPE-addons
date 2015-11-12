#pragma once

#include "Tile.h"

// Size : 144
class TransparentTile : public Tile
{
public:
	bool b1;	// 140

public:
	virtual ~TransparentTile();
	virtual void shouldRenderFace(TileSource *, int, int, int, signed char, const AABB &) const;
};