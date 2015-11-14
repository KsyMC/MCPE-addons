#pragma once

#include "BlockEntityType.h"

class MobSpawnerBlockEntity : public BlockEntity, public FillingContainer
{
public:
	MobSpawnerBlockEntity();
	virtual ~MobSpawnerBlockEntity();
};
