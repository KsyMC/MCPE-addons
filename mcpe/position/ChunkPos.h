#ifndef __CHUNKPOS_H__
#define __CHUNKPOS_H__

struct TilePos;
struct Vec3;
struct Entity;

typedef struct ChunkPos {
	static ChunkPos INVALID;

	int _x;		// 0
	int _z;		// 4

	ChunkPos(const TilePos &);
	ChunkPos(const Vec3 &);
	ChunkPos(float, float, float);
	ChunkPos(int, int, int);
	float distanceToSqr(const Entity *) const;
} CHUNKPOS;

#endif