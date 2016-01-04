#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class BanCommand : public VanillaCommand
{
public:
	BanCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);
};
