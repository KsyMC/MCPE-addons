#pragma once

#include <vector>
#include <string>

class Util
{
public:
	static std::string EMPTY_STRING;

public:
	static std::vector<std::string> split(const std::string &, char);
	static void splitString(std::string const &, char, std::vector<std::string> &);
	static std::string toString(float);
	static std::string toString(int);
	static std::string toLower(const std::string &);
};
