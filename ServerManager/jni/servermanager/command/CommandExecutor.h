#pragma once

#include <string>
#include <vector>

class SMPlayer;
class Command;

class CommandExecutor
{
public:
	virtual ~CommandExecutor() {};

	virtual bool onCommand(SMPlayer *sender, Command *command, std::string &label, std::vector<std::string> &args) = 0;
};
