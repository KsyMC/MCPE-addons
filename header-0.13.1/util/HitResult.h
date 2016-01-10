#pragma once

#include "minecraftpe/block/BlockPos.h"
#include "minecraftpe/entity/Entity.h"
#include "minecraftpe/util/Vec3.h"

class HitResult
{
public:
	int i1;			// 0
	bool b1;		// 4
	BlockPos pos;	// 8
	Vec3 vec3;		// 20
	Entity* e;		// 32
	bool b2;		// 36
};
