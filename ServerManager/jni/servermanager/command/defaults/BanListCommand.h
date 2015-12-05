#pragma once

#include "../Command.h"

class BanListCommand : public Command
{
public:
	BanListCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
