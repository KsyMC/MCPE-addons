#pragma once

#include "../Command.h"

class ServerManager;

class BanIpCommand : public Command
{
public:
	BanIpCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);

	void processIPBan(std::string const &ip, ServerManager *server, std::string const &reason);
};
