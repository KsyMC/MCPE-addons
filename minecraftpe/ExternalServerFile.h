#pragma once

class ExternalServerFile
{
public:
	// Size : 28

public:
	ExternalServerFile(const std::string &);
	void addServer(const std::string &, const std::string &, int);
	void editServer(int, const std::string &, const std::string &, int);
	void getExternalServers();
	void load();
	void removeServer(int);
	void save();
};
