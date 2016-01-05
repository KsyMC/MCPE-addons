#include <fstream>
#include <algorithm>

#include "servermanager/client/resources/BanList.h"
#include "servermanager/client/resources/BanEntry.h"

BanList::BanList(const std::string &file)
{
	this->file = file;
}

BanList::~BanList()
{
	for(BanEntry *entry : banEntries)
		delete entry;

	banEntries.clear();
}

BanEntry *BanList::getBanEntry(const std::string &target) const
{
	for(BanEntry *entry : banEntries)
	{
		if(!entry->getTarget().compare(target))
			return entry;
	}
	return NULL;
}

void BanList::add(BanEntry *entry)
{
	banEntries.push_back(entry);
}

BanEntry *BanList::addBan(const std::string &target, const std::string &reason, const std::string &source)
{
	BanEntry *entry = new BanEntry(target);
	if(!reason.empty())
		entry->setReason(reason);
	if(!source.empty())
		entry->setSource(source);

	banEntries.push_back(entry);

	return entry;
}

std::vector<BanEntry *> BanList::getBanEntries() const
{
	return banEntries;
}

bool BanList::isBanned(const std::string &target) const
{
	for(BanEntry *entry : banEntries)
	{
		if(!entry->getTarget().compare(target))
			return true;
	}
	return false;
}

void BanList::pardon(const std::string &target)
{
	for(BanEntry *entry : banEntries)
	{
		if(!entry->getTarget().compare(target))
		{
			delete entry;
			banEntries.erase(std::find(banEntries.begin(), banEntries.end(), entry));
			break;
		}
	}
}

void BanList::load(const std::string &path)
{
	this->filePath = path + "/" + file;

	std::ifstream ifs(filePath.c_str());
	if(!ifs.is_open())
		return;

	std::string line;
	while(!ifs.eof())
	{
		getline(ifs, line);
		if(line.empty() || line[0] == '#')
			continue;

		BanEntry *entry = BanEntry::fromString(line);
		banEntries.push_back(entry);
	}
	ifs.close();
}

void BanList::save()
{
	std::ofstream ofs(filePath.c_str());
	ofs << "# victim name | banned by | reason" << std::endl << std::endl;

	for(BanEntry *entry : banEntries)
		ofs << entry->getString() << std::endl;
	ofs.close();
}
