#include <fstream>

#include "servermanager/client/settings/SMOptions.h"
#include "servermanager/util/SMUtil.h"
#include "servermanager/version.h"

SMOptions::SMOptions(const std::string &file)
{
	this->file = file;

	serverName = "A Minecraft PE Server";
	serverPort = 19132;
	serverPlayers = 4;

	viewDistance = 10;

	whitelist = false;

	pvpMode = false;

	version = 0;
	updateState = STATE_NOUPDATE;
}

void SMOptions::load(const std::string &path)
{
	filePath = path + file;

	std::ifstream ifs(filePath.c_str());
	if(!ifs.is_open())
		return;

	std::string strLine;
	while(!ifs.eof())
	{
		getline(ifs, strLine);
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

		if(!key.compare("server-name"))
			serverName = value;
		else if(!key.compare("server-port"))
			serverPort = (unsigned short) SMUtil::toInt(value);
		else if(!key.compare("max-players"))
			serverPlayers = SMUtil::toInt(value);
		else if(!key.compare("view-distance"))
			viewDistance = SMUtil::toInt(value);
		else if(!key.compare("white-list"))
			whitelist = (bool) SMUtil::toInt(value);
		else if(!key.compare("pvp"))
			pvpMode = (bool) SMUtil::toInt(value);
		else if(!key.compare("version"))
			version = (char) SMUtil::toInt(value);
	}
	ifs.close();

	if(version != VERSION_CODE)
		updateState = version < VERSION_CODE ? STATE_UPGRADE : STATE_DOWNGRADE;
}

void SMOptions::save()
{
	std::ofstream ofs(filePath.c_str());
	ofs << "server-name:" << serverName << std::endl;
	ofs << "server-port:" << serverPort << std::endl;
	ofs << "max-players:" << serverPlayers << std::endl;
	ofs << "view-distance:" << viewDistance << std::endl;
	ofs << "white-list:" << whitelist << std::endl;
	ofs << "pvp:" << pvpMode << std::endl;
	ofs << "version:" << VERSION_CODE << std::endl;
	ofs.close();
}

void SMOptions::checkOldOptions(const std::string &key, const std::string &value)
{
	switch(updateState)
	{
	case STATE_UPGRADE:
		if(version <= 12) // 4.2
		{
			if(!key.compare("motd"))
				serverName = value;
		}
		break;
	case STATE_DOWNGRADE:
		break;
	}
}
