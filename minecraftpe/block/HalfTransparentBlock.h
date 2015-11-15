#pragma once

#include <minecraftpe/block/Block.h>

// Size : 144
class HalfTransparentTile : public Block
{
public:
	bool b1;	// 140

public:
	HalfTransparentTile(int id, const Material *material) : Block(id, material), b1(true) {};
	HalfTransparentTile(int id, TextureUVCoordinateSet set, const Material *material) : Block(id, set, material), b1(true) {};
	HalfTransparentTile(int id, std::string str, const Material *material) : Block(id, str, material), b1(true) {};
	virtual ~HalfTransparentTile();
	virtual void shouldRenderFace(BlockSource *, int, int, int, signed char, const AABB &) const;
};