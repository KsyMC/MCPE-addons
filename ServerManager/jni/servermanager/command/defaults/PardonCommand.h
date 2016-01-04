#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class PardonCommand : public VanillaCommand
{
public:
	PardonCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);
};
