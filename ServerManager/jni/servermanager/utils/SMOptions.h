#pragma once

#include <string>
#include <vector>

class SMOptions
{
private:
	std::string fileName;

	std::string serverName;
	unsigned short serverPort;
	int serverPlayers;

	bool showIp;
	bool allowOnlyWifiIp;
	bool whitelist;

public:
	SMOptions();

	void load(std::string const &fileName);
	void save();

	std::string getServerName() const {return serverName;}
	unsigned short getServerPort() const {return serverPort;}
	int getServerPlayers() const {return serverPlayers;}

	void setServerName(std::string const &value) {serverName = value;}
	void setServerPort(unsigned short value) {serverPort = value;}
	void setServerPlayers(int value) {serverPlayers = value;}

	bool isShowIp() const {return showIp;}
	bool isAllowOnlyWifiIp() const {return allowOnlyWifiIp;}
	bool isWhitelist() const {return whitelist;}

	void toggleShowIp() {showIp = !showIp;}
	void toggleAllowOnlyWifiIp() {allowOnlyWifiIp = !allowOnlyWifiIp;}
	void toggleWhitelist() {whitelist = !whitelist;}
};
