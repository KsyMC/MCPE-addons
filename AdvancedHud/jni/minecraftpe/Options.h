#pragma once

#include <string>
#include <vector>
#include <functional>

class Options
{
public:
	std::string filepath;	// 0

	void save();
	void _load();
	static void _readBool(std::string const &, bool &);
	static void _readFloat(std::string const &, float &);
	static void _readInt(std::string const &, int &);
};
