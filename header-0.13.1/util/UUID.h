#pragma once

#include "shared.h"

namespace mce
{
class UUID
{
public:
	int part[4];

	void fromString(string const &);
	string toString() const;
};
};
