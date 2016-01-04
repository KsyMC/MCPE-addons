#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class WhitelistCommand : public VanillaCommand
{
public:
	WhitelistCommand();

	bool execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args);
};
