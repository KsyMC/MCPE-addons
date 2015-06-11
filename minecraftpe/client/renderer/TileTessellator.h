#pragma once

#include "texture/TextureUVCoordinateSet.h"
#include "../../util/AABB.h"

class Tile;
class TileSource;
class Tessellator;
class TilePos;

// Size : 72740
class TileTessellator
{
public:
	static TileTessellator *instance;

public:
	char filler1[4];				// 0
	TileSource *tileSource;			// 4
	TextureUVCoordinateSet texture;	// 8
	bool renderTexture;				// 40
	char filler2[623];				// 41
	Tessellator* tessellator;		// 664
	AABB aabb;						// 668

public:
	bool tessellateInWorld(Tile *, const TilePos &, bool);
	void tessellateBlockInWorld(Tile *, const TilePos &);
	uint getLightColor(const TilePos &);
	void tex1(uint);
};
