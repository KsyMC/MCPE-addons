#pragma once

// Size : 28
class ExternalServerFile
{
public:
	ExternalServerFile(const std::string &);
	void addServer(const std::string &, const std::string &, int);
	void editServer(int, const std::string &, const std::string &, int);
	void getExternalServers();
	void load();
	void removeServer(int);
	void save();
};
