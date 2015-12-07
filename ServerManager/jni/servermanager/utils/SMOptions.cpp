#include <fstream>

#include "SMOptions.h"
#include "SMUtil.h"

#include "minecraftpe/Options.h"
#include "shared.h"

SMOptions::SMOptions()
{
	serverName = "ServerManager";
	serverPort = 19132;
	serverPlayers = 4;

	showIp = false;
	allowOnlyWifiIp = false;
	whitelist = false;
}

void SMOptions::load(std::string const &fileName)
{
	this->fileName = fileName;

	std::ifstream ifs(fileName.c_str());
	if(!ifs.is_open())
		return;

	std::string strLine;
	while(!ifs.eof())
	{
		std::getline(ifs, strLine);
		if(strLine.empty())
			continue;

		std::vector<std::string> s = SMUtil::split(strLine, ':');

		if(s.empty() || s.size() < 2 || s[0].empty() || s[1].empty())
			continue;

		std::string key = s[0];
		std::string value = s[1];

		if(s.size() > 2)
		{
			s.erase(s.begin());
			for(int i = 0; i < s.size(); i++)
				value += ":" + s[i];
		}

		if(!key.compare("motd"))
			serverName = value;
		else if(!key.compare("server-port"))
		{
			int port;
			Options::_readInt(value, port);

			serverPort = port;
		}
		else if(!key.compare("max-players"))
			Options::_readInt(value, serverPlayers);
		else if(!key.compare("white-list"))
			Options::_readBool(value, whitelist);
		else if(!key.compare("show-ip"))
			Options::_readBool(value, showIp);
		else if(!key.compare("allow-only-wifi-ip"))
			Options::_readBool(value, allowOnlyWifiIp);
		else if(!key.compare("version"))
		{
			int version;
			Options::_readInt(value, version);
		}
	}
	ifs.close();
}

void SMOptions::save()
{
	std::ofstream ofs(fileName.c_str());
	ofs << "motd:" << serverName << std::endl;
	ofs << "server-port:" << serverPort << std::endl;
	ofs << "max-players:" << serverPlayers << std::endl;
	ofs << "white-list:" << whitelist << std::endl;
	ofs << "show-ip:" << showIp << std::endl;
	ofs << "allow-only-wifi-ip:" << allowOnlyWifiIp << std::endl;
	ofs << "version:" << VERSION << std::endl;
	ofs.close();
}
