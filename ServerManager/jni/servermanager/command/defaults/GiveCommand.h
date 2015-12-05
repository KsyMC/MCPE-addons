#pragma once

#include "../Command.h"

class GiveCommand : public Command
{
public:
	GiveCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
