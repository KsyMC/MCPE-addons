#pragma once

#include <string>
#include "IntRectangle.h"

class ImageDef
{
public:
	std::string textureName;	// 0
	int	x;						// 4
	int	y;						// 8
	float width;				// 12
	float height;				// 16
	IntRectangle intRectangle;	// 20
	bool crop;					// 36
};
