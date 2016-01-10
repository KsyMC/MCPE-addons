#pragma once

#include "minecraftpe/block/BlockProperty.h"

class BlockID
{
public:
	static BlockID AIR;

public:
	unsigned char id;	// 0

public:
	BlockID() : id(0) {}
	BlockID(unsigned char id) : id(id) {}
	BlockID(BlockID const &other) {id = other.id;}
	bool hasProperty(BlockProperty) const;
};
