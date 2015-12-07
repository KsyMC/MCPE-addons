#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>

class SMUtil
{
public:
	static bool is_number(std::string const &s)
	{
		std::string::const_iterator it = s.begin();
		if(s.size() > 1 && (s[0] == '-' || s[0] == '+')) it++;
		while (it != s.end() && std::isdigit(*it)) ++it;
		return !s.empty() && it == s.end();
	}

	static int toInt(std::string const &str)
	{
		return atoi(str.c_str());
	}

	static float toFloat(std::string const &str)
	{
		return (float)toDouble(str);
	}

	static double toDouble(std::string const &str)
	{
		return strtod(str.c_str(), NULL);
	}

	template <typename T>
	static std::string toString(T num)
	{
		std::ostringstream ss;
		ss << num;
		return ss.str();
	}

	static std::string toLower(std::string const &str)
	{
		std::string temp = str;
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		return temp;
	}

	static std::string join(std::vector<std::string> const &v, std::string const &g)
	{
		std::stringstream ss;
		for(size_t i = 0; i < v.size(); i++)
		{
			if(i != 0)
				ss << g;
			ss << v[i];
		}
		return ss.str();
	}

	static std::vector<std::string> &split(std::string const &s, char delim, std::vector<std::string> &elems)
	{
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim))
			elems.push_back(item);
		return elems;
	}

	static std::vector<std::string> split(std::string const &s, char delim)
	{
		std::vector<std::string> elems;
		split(s, delim, elems);
		return elems;
	}

	// trim from start
	static std::string ltrim(std::string const &s)
	{
		std::string temp = s;
		temp.erase(temp.begin(), std::find_if(temp.begin(), temp.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
		return temp;
	}

	// trim from end
	static std::string rtrim(std::string const &s)
	{
		std::string temp = s;
		temp.erase(std::find_if(temp.rbegin(), temp.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), temp.end());
		return temp;
	}

	// trim from both ends
	static std::string trim(std::string const &s)
	{
		return ltrim(rtrim(s));
	}

	static std::string format(char const *format)
	{
		char buffer[256];
		va_list args;
		va_start (args, format);
		vsnprintf (buffer, 256, format, args);
		va_end (args);
		return buffer;
	}
};
