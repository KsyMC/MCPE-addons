#include <algorithm>
#include <fstream>

#include "SMList.h"

SMList::SMList() {}

void SMList::load(std::string const &fileName)
{
	this->fileName = fileName;

	std::ifstream ifs(fileName.c_str());
	if(!ifs.is_open())
		return;

	std::string line;
	while(!ifs.eof())
	{
		std::getline(ifs, line);
		if(line.empty())
			continue;

		list.push_back(line);
	}
	ifs.close();
}

void SMList::save()
{
	std::ofstream ofs(fileName.c_str());
	for(auto str : list)
		ofs << str << std::endl;
	ofs.close();
}

void SMList::reload()
{
	load(fileName);
}

void SMList::add(std::string const &element)
{
	if(isExist(element))
		return;

	list.push_back(element);
}

void SMList::remove(std::string const &element)
{
	if(!isExist(element))
		return;

	list.erase(std::find(list.begin(), list.end(), element));
}

bool SMList::isExist(std::string const &element) const
{
	return std::find(list.begin(), list.end(), element) != list.end();
}

std::vector<std::string> SMList::getAll() const
{
	return list;
}
