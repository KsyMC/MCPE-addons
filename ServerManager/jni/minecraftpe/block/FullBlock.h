#pragma once

#include "minecraftpe/block/BlockID.h"

class FullBlock
{
public:
	static FullBlock AIR;

public:
	BlockID id;			// 0
	unsigned char aux;	// 4

public:
	FullBlock() : id(0), aux(0) {};
	FullBlock(BlockID id, unsigned char aux) : id(id), aux(aux) {}
};
