#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class BanIpCommand : public VanillaCommand
{
public:
	BanIpCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);
	void processIPBan(const std::string &ip, SMPlayer *player, const std::string &reason);
};
