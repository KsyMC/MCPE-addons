#pragma once

#include <string>

class Textures;
class NinePatchLayer;
class IntRectangle;

// Size : 16
class NinePatchFactory
{
public:
	Textures *textures;			// 0
	std::string textureFile;	// 4
	char filler1[8];			// 8

public:
	NinePatchFactory(Textures *, const std::string &);
	NinePatchLayer *createSymmetrical(const IntRectangle &, int, int, float, float);
};
