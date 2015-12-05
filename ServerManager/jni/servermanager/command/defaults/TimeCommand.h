#pragma once

#include "../Command.h"

class TimeCommand : public Command
{
public:
	TimeCommand(std::string const &name);

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args);
};
