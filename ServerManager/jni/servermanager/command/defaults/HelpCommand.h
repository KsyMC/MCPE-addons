#pragma once

#include "../Command.h"

class HelpCommand : public Command
{
public:
	HelpCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
