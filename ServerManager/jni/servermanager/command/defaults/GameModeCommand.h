#pragma once

#include "../Command.h"

class GameModeCommand : public Command
{
public:
	GameModeCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
