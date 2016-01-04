#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class KickCommand : public VanillaCommand
{
public:
	KickCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);
};
