#ifndef __TILEPOS_H__
#define __TILEPOS_H__

struct ChunkPos;
struct Vec3;

typedef struct TilePos {
	int _x;		// 0
	int _y;		// 4
	int _z;		// 8

	TilePos(const ChunkPos &, int);
	TilePos(const Vec3 &);
	TilePos(float, float, float);
} TILEPOS;

#endif
