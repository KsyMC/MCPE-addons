#pragma once

#include <minecraftpe/util/BlockID.h>

class FullBlock
{
public:
	static FullBlock AIR;

public:
	BlockID tileID;
	unsigned char damage;

public:
	FullBlock() : tileID(0), damage(0) {};
	FullBlock(BlockID tileId, unsigned char damage) : tileID(tileId), damage(damage) {}
};
