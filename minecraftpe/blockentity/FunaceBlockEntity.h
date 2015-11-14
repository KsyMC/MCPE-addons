#pragma once

#include "BlockEntity.h"

class FunaceBlockEntity : public BlockEntity, public FillingContainer
{
public:
	FunaceBlockEntity();
	virtual ~FunaceBlockEntity();
};
