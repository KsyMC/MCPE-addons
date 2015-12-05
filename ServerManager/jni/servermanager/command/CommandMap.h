#pragma once

#include <string>

class Command;
class SMPlayer;

class CommandMap
{
public:
	virtual ~CommandMap() {};

	virtual bool registerCommand(Command *command, std::string const &label = "") = 0;

	virtual bool dispatch(SMPlayer *sender, std::string const &cmdLine) = 0;
};
