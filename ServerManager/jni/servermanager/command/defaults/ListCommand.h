#pragma once

#include "../Command.h"

class ListCommand : public Command
{
public:
	ListCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
