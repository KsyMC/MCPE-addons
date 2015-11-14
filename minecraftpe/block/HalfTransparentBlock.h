#pragma once

#include <minecraftpe/block/Block.h>

// Size : 144
class HalfTransparentTile : public Tile
{
public:
	bool b1;	// 140

public:
	HalfTransparentTile(int id, const Material *material) : Tile(id, material), b1(true) {};
	HalfTransparentTile(int id, TextureUVCoordinateSet set, const Material *material) : Tile(id, set, material), b1(true) {};
	HalfTransparentTile(int id, std::string str, const Material *material) : Tile(id, str, material), b1(true) {};
	virtual ~HalfTransparentTile();
	virtual void shouldRenderFace(TileSource *, int, int, int, signed char, const AABB &) const;
};