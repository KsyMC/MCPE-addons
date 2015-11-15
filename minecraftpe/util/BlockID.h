#pragma once

class BlockID
{
public:
	static BlockID AIR;

public:
	unsigned char id;	// 0

public:
	BlockID() : id(0) {}
	BlockID(unsigned char id) : id(id) {}
	BlockID(const BlockID &other) {id = other.id;}
};
