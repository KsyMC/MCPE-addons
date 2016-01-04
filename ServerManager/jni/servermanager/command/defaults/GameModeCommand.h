#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class GameModeCommand : public VanillaCommand
{
public:
	GameModeCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);
};
