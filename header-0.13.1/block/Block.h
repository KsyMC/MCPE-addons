#pragma once

#include "shared.h"

class Block
{
public:
	char filler[4];		// 0
	unsigned char id;	// 4

	static Block *lookupByName(string const &, bool);
};
