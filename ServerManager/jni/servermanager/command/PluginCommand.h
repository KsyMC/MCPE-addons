#pragma once

#include "servermanager/command/Command.h"
#include "servermanager/command/PluginIdentifiableCommand.h"

class CommandExecutor;

class PluginCommand : public Command, public PluginIdentifiableCommand
{
private:
	Plugin *owningPlugin;
	CommandExecutor *executor;

public:
	PluginCommand(const std::string &name, Plugin *owner);

	bool execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args);

	bool isPluginCommand() const;

	void setExecutor(CommandExecutor *executor);
	CommandExecutor *getExecutor() const;

	Plugin *getPlugin() const;
};
