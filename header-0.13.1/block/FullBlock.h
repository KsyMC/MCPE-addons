#pragma once

#include "minecraftpe/block/BlockID.h"

class FullBlock
{
public:
	static FullBlock AIR;

public:
	BlockID id;
	unsigned char aux;

public:
	FullBlock() : id(0), aux(0) {};
	FullBlock(BlockID id, unsigned char aux) : id(id), aux(aux) {}
};
