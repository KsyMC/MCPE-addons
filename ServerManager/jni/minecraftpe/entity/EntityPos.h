#pragma once

#include "minecraftpe/util/Vec3.h"
#include "minecraftpe/util/Vec2.h"

// Size : 22
struct EntityPos
{
	Vec3 pos;			// 0
	Vec2 rot;			// 12
	bool rotation;		// 20
	bool teleport;		// 21
};
