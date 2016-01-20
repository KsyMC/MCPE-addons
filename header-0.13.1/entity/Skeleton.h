#pragma once

#include "minecraftpe/entity/Monster.h"

class Skeleton : public Monster
{
public:
	enum class SkeletonType {
		NORMAL,
		WITHER
	};
};
