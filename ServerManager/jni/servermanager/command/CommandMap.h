#pragma once

#include <string>
#include <vector>
#include <map>

class Command;
class SMPlayer;

class CommandMap
{
private:
	std::vector<Command *> commands;
	std::map<std::string, Command *> knownCommands;

public:
	CommandMap();
	~CommandMap();

	void setDefaultCommands();
	void setFallbackCommands();

	void registerAll(const std::string &fallbackPrefix, std::vector<Command *> commands);
	bool registerCommand(const std::string &fallbackPrefix, Command *command);
	bool registerCommand(const std::string &label, const std::string &fallbackPrefix, Command *command);
	bool registerCommand(const std::string &label, Command *command, bool isAlias, const std::string &fallbackPrefix);

	bool dispatch(SMPlayer *sender, const std::string &cmdLine);

	void clearCommands();

	Command *getCommand(const std::string &name);
	const std::map<std::string, Command *> &getCommands() const;
};
