#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class TeleportCommand : public VanillaCommand
{
public:
	TeleportCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);
};
