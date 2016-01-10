#pragma once

#include "minecraftpe/entity/Mob.h"

class Creeper : public Mob
{
public:
	void _setPowered(bool);
	bool isPowered() const;
};
