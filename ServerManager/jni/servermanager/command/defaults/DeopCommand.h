#pragma once

#include "../Command.h"

class DeopCommand : public Command
{
public:
	DeopCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
