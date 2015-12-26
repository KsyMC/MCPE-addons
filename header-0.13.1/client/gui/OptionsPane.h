#pragma once

#include "shared.h"

class OptionsGroup;

class OptionsPane
{
public:
	OptionsGroup *createOptionsGroup(string const &, bool);
};
