#pragma once

#include <string>
#include <functional>

class stat;

class File
{
public:
	static void cleanPath(const std::string &);
	static void copy(const std::string &, const std::string &);
	static void createFolder(const std::string &);
	static void deleteDirectory(const std::string &, bool);
	static void deleteEmptyDirectory(const std::string &);
	static bool exists(const std::string &);
	static void forEachIn(const std::string &, bool, std::function<void (const std::string &, const stat &)> const&);
	static int getRemainingSize(__sFILE *);
	static int getSize(const std::string &);
	static bool isDirectory(const stat &);
	static void splitPath(const std::string &);
};