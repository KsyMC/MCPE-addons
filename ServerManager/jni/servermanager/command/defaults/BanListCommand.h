#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class BanListCommand : public VanillaCommand
{
public:
	BanListCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);
};
