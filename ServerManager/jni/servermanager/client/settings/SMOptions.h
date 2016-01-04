#pragma once

#include <string>

class SMOptions
{
private:
	std::string file;
	std::string filePath;
	std::string serverName;
	unsigned short serverPort;
	int serverPlayers;
	int viewDistance;
	bool whitelist;
	bool pvpMode;

	enum UpdateState
	{
		STATE_NOUPDATE,
		STATE_UPGRADE,
		STATE_DOWNGRADE,
	};

	char version;
	UpdateState updateState;

public:
	SMOptions(const std::string &file);

	void load(const std::string &path);
	void save();

	void checkOldOptions(const std::string &key, const std::string &value);

	std::string getServerName() const { return serverName; }
	unsigned short getServerPort() const { return serverPort; }
	int getServerPlayers() const { return serverPlayers; }
	int getViewDistance() const { return viewDistance; }
	bool hasWhitelist() const { return whitelist; }
	bool getPvP() const { return pvpMode; }

	void setServerName(const std::string &value) { serverName = value; }
	void setServerPort(unsigned short value) { serverPort = value; }
	void setServerPlayers(int value) { serverPlayers = value; }
	void setViewDistance(int value) { viewDistance = value; }
	void setWhitelist(bool value) { whitelist = value; }
	void setPvP(bool value) { pvpMode = value; }

	char getOldVersion() const { return version; };
	int getUpdateState() const { return updateState; }
};
