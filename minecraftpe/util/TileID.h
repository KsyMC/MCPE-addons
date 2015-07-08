#pragma once

class TileID
{
public:
	static TileID AIR;

public:
	unsigned char id;	// 0

public:
	TileID() : id(0) {}
	TileID(unsigned char id) : id(id) {}
	TileID(const TileID &other) {id = other.id;}
};
