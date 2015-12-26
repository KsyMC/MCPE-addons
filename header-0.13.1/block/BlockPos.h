#pragma once

#include "shared.h"

class ChunkPos;
class Vec3;

// Size : 12
class BlockPos
{
public:
	int x;		// 0
	int y;		// 4
	int z;		// 8

public:
	BlockPos() : x(0), y(0), z(0) {}
	BlockPos(int x, int y, int z) : x(x), y(y), z(z) {}
	BlockPos(ChunkPos const &, int);
	BlockPos(Vec3 const &);
	BlockPos(float, float, float);
	void neighbor(signed char) const;
	void relative(signed char, int) const;
};
