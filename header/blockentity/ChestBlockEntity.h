#pragma once

#include "BlockEntityType.h"

class ChestBlockEntity : public BlockEntity, public FillingContainer
{
public:
	ChestBlockEntity();
	virtual ~ChestBlockEntity();
};
