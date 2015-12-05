#pragma once

#include "../Command.h"

class TellCommand : public Command
{
public:
	TellCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
