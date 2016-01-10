#pragma once

#include <string>
#include <vector>

class I18n
{
public:
	static std::string get(const std::string &);
	static std::string get(const std::string &, const std::vector<std::string> &);
};
