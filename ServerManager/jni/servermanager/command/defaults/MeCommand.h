#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class MeCommand : public VanillaCommand
{
public:
	MeCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);
};
