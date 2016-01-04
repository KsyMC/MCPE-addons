#include "servermanager/command/defaults/TimeCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/Server.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/level/SMLevel.h"
#include "servermanager/util/SMUtil.h"
#include "minecraftpe/level/Level.h"

TimeCommand::TimeCommand()
	: VanillaCommand("time")
{
	description = "Changes the time on each world";
	usageMessage = "/time <set|add> <value> OR /time <start|stop|query>";
}

bool TimeCommand::execute(SMPlayer *sender, std::string &commandLabel, std::vector<std::string> &args)
{
	if((int)args.size() < 1)
	{
		sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
		return false;
	}

	if(!args[0].compare("start"))
	{
		ServerManager::getLevel()->getHandle()->setDayCycleActive(true);
		Command::broadcastCommandMessage(sender, "Restarted the time");
	}
	else if(!args[0].compare("stop"))
	{
		ServerManager::getLevel()->getHandle()->setDayCycleActive(false);
		Command::broadcastCommandMessage(sender, "Stopped the time");
	}
	else if(!args[0].compare("query"))
		sender->sendTranslation("commands.time.query", {SMUtil::toString(ServerManager::getLevel()->getHandle()->getTime())});
	else if(!args[0].compare("set"))
	{
		if((int)args.size() < 2)
		{
			sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
			return false;
		}

		int value;

		if(!args[1].compare("day"))
			value = 0;
		else if(!args[1].compare("night"))
			value = 14000;
		else
			value = getInteger(sender, args[1], 0);

		ServerManager::getLevel()->getHandle()->setTime(value);
		Command::broadcastCommandTranslation(sender, "commands.time.set", {SMUtil::toString(value)});
	}
	else if(!args[0].compare("add"))
	{
		if((int)args.size() < 2)
		{
			sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
			return false;
		}

		int value = getInteger(sender, args[1], 0);

		ServerManager::getLevel()->getHandle()->setTime(ServerManager::getLevel()->getHandle()->getTime() + value);
		Command::broadcastCommandTranslation(sender, "commands.time.added", {SMUtil::toString(value)});
	}
	else
		sender->sendTranslation("§c%commands.generic.usage", {usageMessage});

	return true;
}
