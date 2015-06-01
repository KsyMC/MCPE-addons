#pragma once

#include <string>

class Util
{
public:
	static std::string EMPTY_STRING;

public:
	static std::string toString(float);
	static std::string toString(int);
	static std::string toLower(const std::string &);
};