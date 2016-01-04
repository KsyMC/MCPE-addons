#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class PardonIpCommand : public VanillaCommand
{
public:
	PardonIpCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);
};
