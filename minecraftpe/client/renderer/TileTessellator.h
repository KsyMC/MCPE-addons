#pragma once

#include "texture/TextureUVCoordinateSet.h"
#include "../../util/AABB.h"

class Block;
class BlockSource;
class Tessellator;
class BlockPos;

// Size : 72740
class TileTessellator
{
public:
	static TileTessellator *instance;

public:
	char filler1[4];				// 0
	BlockSource *tileSource;			// 4
	TextureUVCoordinateSet texture;	// 8
	bool renderTexture;				// 40
	char filler2[623];				// 41
	Tessellator* tessellator;		// 664
	AABB aabb;						// 668

public:
	bool tessellateInWorld(Block *, const BlockPos &, bool);
	void tessellateBlockInWorld(Block *, const BlockPos &);
	uint getLightColor(const BlockPos &);
	void tex1(uint);
};
