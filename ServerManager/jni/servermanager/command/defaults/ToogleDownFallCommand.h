#pragma once

#include "../Command.h"

class ToogleDownFallCommand : public Command
{
public:
	ToogleDownFallCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
