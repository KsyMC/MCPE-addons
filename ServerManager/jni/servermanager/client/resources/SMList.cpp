#include <algorithm>
#include <fstream>

#include "servermanager/client/resources/SMList.h"

SMList::SMList(const std::string &file)
{
	this->file = file;
}

void SMList::load(const std::string &path)
{
	this->filePath = path + "/" + file;

	std::ifstream ifs(filePath.c_str());
	if(!ifs.is_open())
		return;

	std::string line;
	while(!ifs.eof())
	{
		getline(ifs, line);
		if(line.empty())
			continue;

		list.push_back(line);
	}
	ifs.close();
}

void SMList::save()
{
	std::ofstream ofs(filePath.c_str());
	for(auto str : list)
		ofs << str << std::endl;
	ofs.close();
}

void SMList::reload()
{
	load(filePath);
}

void SMList::add(const std::string &element)
{
	if(isExist(element))
		return;

	list.push_back(element);
}

void SMList::remove(const std::string &element)
{
	if(!isExist(element))
		return;

	list.erase(std::find(list.begin(), list.end(), element));
}

bool SMList::isExist(const std::string &element) const
{
	return std::find(list.begin(), list.end(), element) != list.end();
}

const std::vector<std::string> &SMList::getAll() const
{
	return list;
}
