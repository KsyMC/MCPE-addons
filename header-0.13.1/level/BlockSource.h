#pragma once

#include "shared.h"

class Level;

// Size : 68
class BlockSource
{
public:
	Level *getLevel();
	Level *getLevel() const;
	Level *getLevelConst() const;
};
