#pragma once

#include "../Command.h"

class WhitelistCommand : public Command
{
public:
	WhitelistCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
