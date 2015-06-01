#pragma once

class ChunkPos;
class Vec3;

class TilePos
{
public:
	int x;		// 0
	int y;		// 4
	int z;		// 8

public:
	TilePos(const ChunkPos &, int);
	TilePos(const Vec3 &);
	TilePos(float, float, float);
};