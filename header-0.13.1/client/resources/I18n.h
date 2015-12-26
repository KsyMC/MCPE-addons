#pragma once

#include "shared.h"

class I18n
{
public:
	static string get(string const &);
	static string get(string const &, vector<string> const &);
};
