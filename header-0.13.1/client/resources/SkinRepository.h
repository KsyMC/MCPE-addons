#pragma once

#include "shared.h"

class SkinPack;

class SkinRepository
{
public:
	char filler[32];
	vector<SkinPack *> skinPacks;
};
