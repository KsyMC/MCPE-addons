#ifndef __UTIL_H__
#define __UTIL_H__

class Util {
public:
	static std::string EMPTY_STRING;

public:
	static std::string toString(float);
	static std::string toString(int);
	static std::string toLower(const std::string &);
};

#endif
