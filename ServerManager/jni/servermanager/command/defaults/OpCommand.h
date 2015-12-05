#pragma once

#include "../Command.h"

class OpCommand : public Command
{
public:
	OpCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
