#include "TimeCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "../../level/SMLevel.h"
#include "../../utils/SMUtil.h"

#include "minecraftpe/Level.h"

TimeCommand::TimeCommand(std::string const &name)
	: Command(name,
			"Changes the time on each world",
			"/time <set|add> <value> OR /time <start|stop|query>") {}

bool TimeCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() < 1)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	if(!args[0].compare("start"))
	{
		sender->getLevel()->get()->setDayCycleActive(true);

		Command::broadcastCommandMessage(sender, TextContainer("Restarted the time"));
	}
	else if(!args[0].compare("stop"))
	{
		sender->getLevel()->get()->setDayCycleActive(false);

		Command::broadcastCommandMessage(sender, TextContainer("Stopped the time"));
	}
	else if(!args[0].compare("query"))
		sender->sendMessage(TextContainer("commands.time.query", {SMUtil::toString(sender->getLevel()->get()->getTime())}));
	else if(!args[0].compare("set"))
	{
		if((int)args.size() < 2)
		{
			sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
			return false;
		}

		int value;

		if(!args[1].compare("day"))
			value = 0;
		else if(!args[1].compare("night"))
			value = 14000;
		else
			value = getInteger(sender, args[1], 0);

		sender->getLevel()->get()->setTime(value);

		Command::broadcastCommandMessage(sender, TextContainer("commands.time.set", {SMUtil::toString(value)}));
	}
	else if(!args[0].compare("add"))
	{
		if((int)args.size() < 2)
		{
			sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
			return false;
		}

		int value = getInteger(sender, args[1], 0);

		Level *level = sender->getLevel()->get();
		level->setTime(level->getTime() + value);

		Command::broadcastCommandMessage(sender, TextContainer("commands.time.added", {SMUtil::toString(value)}));
	}
	else
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));

	return true;
}
