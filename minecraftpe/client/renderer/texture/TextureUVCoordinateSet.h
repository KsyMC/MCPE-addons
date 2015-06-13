#pragma once

#include "TextureFile.h"

// Size : 32
class TextureUVCoordinateSet
{
public:
	float startX;		// 0
	float startY;		// 4
	float endX;			// 8
	float endY;			// 12
	float width;		// 16
	float height;		// 20
	int i1;				// 24
	char filler1[4];	// 28
	TextureFile type;	// 28

public:
	TextureUVCoordinateSet(float, float, float, float, float, float, int, TextureFile);
	TextureUVCoordinateSet();
	void fix();
};
