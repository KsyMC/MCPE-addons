#pragma once

#include <string>

class OptionsGroup;

class OptionsPane
{
public:
	OptionsGroup *createOptionsGroup( const std::string &, bool );
};
