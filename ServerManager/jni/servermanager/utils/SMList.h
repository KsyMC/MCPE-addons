#pragma once

#include <string>
#include <vector>

class SMList
{
private:
	std::string fileName;
	std::vector<std::string> list;

public:
	SMList();

	void load(std::string const &fileName);
	void save();

	void reload();

	void add(std::string const &element);
	void remove(std::string const &element);
	bool isExist(std::string const &element) const;

	std::vector<std::string> getAll() const;
};
