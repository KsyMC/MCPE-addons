#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class TellCommand : public VanillaCommand
{
public:
	TellCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);
};
