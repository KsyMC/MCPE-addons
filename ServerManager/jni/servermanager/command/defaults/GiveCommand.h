#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class GiveCommand : public VanillaCommand
{
public:
	GiveCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);
};
