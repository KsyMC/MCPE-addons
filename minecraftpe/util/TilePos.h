#pragma once

class ChunkPos;
class Vec3;

// Size : 12
class TilePos
{
public:
	int x;		// 0
	int y;		// 4
	int z;		// 8

public:
	TilePos() : x(0), y(0), z(0) {}
	TilePos(int x, int y, int z) : x(x), y(y), z(z) {}
	TilePos(const ChunkPos &, int);
	TilePos(const Vec3 &);
	TilePos(float, float, float);
	void neighbor(signed char) const;
	void relative(signed char, int) const;
};
