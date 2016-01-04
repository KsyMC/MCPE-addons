#include "servermanager/command/PluginCommand.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/command/CommandExecutor.h"
#include "servermanager/plugin/Plugin.h"
#include "servermanager/util/SMUtil.h"

PluginCommand::PluginCommand(const std::string &name, Plugin *owner)
	: Command(name)
{
	this->executor = owner;
	this->owningPlugin = owner;
}

bool PluginCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	bool success = false;

	if(!owningPlugin->isEnabled())
		return false;

	success = executor->onCommand(sender, this, label, args);

	if(!success && usageMessage.length() > 0)
	{
		std::string newUsage = usageMessage;
		if(newUsage.find("<command>") != std::string::npos)
		{
			std::string findString = "<command>";
			newUsage.replace(newUsage.find(findString), findString.length(), label);
		}

		for(std::string line : SMUtil::split(newUsage, '\n'))
			sender->sendMessage(line);
	}

	return success;
}

bool PluginCommand::isPluginCommand() const
{
	return true;
}

void PluginCommand::setExecutor(CommandExecutor *executor)
{
	this->executor = !executor ? owningPlugin : executor;
}

CommandExecutor *PluginCommand::getExecutor() const
{
	return executor;
}

Plugin *PluginCommand::getPlugin() const
{
	return owningPlugin;
}
