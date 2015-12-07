#pragma once

#include "../Command.h"

class TeleportCommand : public Command
{
public:
	TeleportCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
