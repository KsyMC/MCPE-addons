#pragma once

#include <string>
#include "IntRectangle.h"

// Size : 40
class ImageDef
{
public:
	std::string textureName;	// 0
	int	xLeft;					// 4
	int	yTop;					// 8
	float width;				// 12
	float height;				// 16
	IntRectangle intRectangle;	// 20
	bool crop;					// 36
};
