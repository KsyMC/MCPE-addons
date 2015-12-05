#pragma once

#include "BlockEntityType.h"

class SignBlockEntity : public BlockEntity, public FillingContainer
{
public:
	SignBlockEntity();
	virtual ~SignBlockEntity();
};
