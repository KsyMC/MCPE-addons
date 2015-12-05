#pragma once

#include "Block.h"

// Size : 144
class HalfTransparentBlock : public Block
{
public:
	bool b1;	// 140

public:
	HalfTransparentBlock(std::string const &, int, std::string const &, Material const &, bool);
	virtual ~HalfTransparentBlock();
};
