#pragma once

#include <string>
#include <vector>

class SMList
{
private:
	std::string file;
	std::string filePath;
	std::vector<std::string> list;

public:
	SMList(const std::string &file);

	void load(const std::string &path);
	void save();

	void reload();

	void add(const std::string &element);
	void remove(const std::string &element);
	bool isExist(const std::string &element) const;

	const std::vector<std::string> &getAll() const;
};
