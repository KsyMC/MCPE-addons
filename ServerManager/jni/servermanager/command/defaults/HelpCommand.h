#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class HelpCommand : public VanillaCommand
{
public:
	HelpCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);
};
