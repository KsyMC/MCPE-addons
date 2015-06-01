#pragma once

class TilePos;
class Vec3;
class Entity;

class ChunkPos
{
public:
	static ChunkPos INVALID;

public:
	int x;	// 0
	int z;	// 4

public:
	ChunkPos(const TilePos &);
	ChunkPos(const Vec3 &);
	ChunkPos(float, float, float);
	ChunkPos(int, int, int);
	float distanceToSqr(const Entity *) const;
};