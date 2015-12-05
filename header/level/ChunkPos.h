#pragma once

class BlockPos;
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
	ChunkPos(const BlockPos &);
	ChunkPos(const Vec3 &);
	ChunkPos(float, float, float);
	ChunkPos(int, int, int);
	float distanceToSqr(const Entity *) const;
};