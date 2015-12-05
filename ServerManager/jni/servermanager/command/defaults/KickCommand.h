#pragma once

#include "../Command.h"

class KickCommand : public Command
{
public:
	KickCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
