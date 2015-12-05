#pragma once

#include "../Command.h"

class BanCommand : public Command
{
public:
	BanCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
