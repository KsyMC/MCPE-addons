#pragma once

#include "shared.h"

class Item
{
public:
	char filler1[18];	// 0
	unsigned short id;	// 18

	static Item *lookupByName(string const &, bool);
};
