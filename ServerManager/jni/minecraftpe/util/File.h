#pragma once

#include <string>

class File
{
public:
	static bool createFolder(const std::string &);
	static bool exists(const std::string &);
};
