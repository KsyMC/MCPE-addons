#pragma once

#include <string>
#include <vector>
#include <sstream>

class SMUtil
{
public:
	static bool is_number(const std::string &s);
	static int toInt(const std::string &str);
	static float toFloat(const std::string &str);
	static double toDouble(const std::string &str);

	template <typename T>
	static std::string toString(T num)
	{
		std::ostringstream ss;
		ss << num;
		return ss.str();
	}

	static std::string toLower(const std::string &str);
	static std::string join(const std::vector<std::string> &v, const std::string &g);
	static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
	static std::vector<std::string> split(const std::string &s, char delim);

	static std::string ltrim(const std::string &s);
	static std::string rtrim(const std::string &s);
	static std::string trim(const std::string &s);

	static std::string format(const char *format, ...);
};
