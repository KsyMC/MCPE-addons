#include <cstdlib>
#include <algorithm>

#include "servermanager/util/SMUtil.h"

bool SMUtil::is_number(const std::string &s)
{
	std::string::const_iterator it = s.begin();
	if(s.size() > 1 && (s[0] == '-' || s[0] == '+')) it++;
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

int SMUtil::toInt(const std::string &str)
{
	return atoi(str.c_str());
}

float SMUtil::toFloat(const std::string &str)
{
	return (float)toDouble(str);
}

double SMUtil::toDouble(const std::string &str)
{
	return strtod(str.c_str(), NULL);
}

std::string SMUtil::toLower(const std::string &str)
{
	std::string temp = str;
	std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	return temp;
}

std::string SMUtil::join(const std::vector<std::string> &v, const std::string &g)
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

std::vector<std::string> &SMUtil::split(const std::string &s, char delim, std::vector<std::string> &elems)
{
	std::stringstream ss(s);
	std::string item;
	while (getline(ss, item, delim))
		elems.push_back(item);
	return elems;
}

std::vector<std::string> SMUtil::split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

// trim from start
std::string SMUtil::ltrim(const std::string &s)
{
	std::string temp = s;
	temp.erase(temp.begin(), std::find_if(temp.begin(), temp.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return temp;
}

// trim from end
std::string SMUtil::rtrim(const std::string &s)
{
	std::string temp = s;
	temp.erase(std::find_if(temp.rbegin(), temp.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), temp.end());
	return temp;
}

// trim from both ends
std::string SMUtil::trim(const std::string &s)
{
	return ltrim(rtrim(s));
}

std::string SMUtil::format(const char *format, ...)
{
	char buffer[256];
	va_list args;
	va_start (args, format);
	vsnprintf (buffer, 256, format, args);
	va_end (args);
	return buffer;
}
