#pragma once

#include <string>
#include <vector>

class BanEntry;

class BanList
{
public:
	enum Type
	{
		NAME,
		IP
	};

private:
	std::string file;
	std::string filePath;

	std::vector<BanEntry *> banEntries;

public:
	BanList(const std::string &file);
	~BanList();

	BanEntry *getBanEntry(const std::string &target) const;

	void add(BanEntry *entry);
	BanEntry *addBan(const std::string &target, const std::string &reason, const std::string &source);

	std::vector<BanEntry *> getBanEntries() const;

	bool isBanned(const std::string &target) const;

	void pardon(const std::string &target);

	void load(const std::string &path);
	void save();
};
