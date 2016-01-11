#include "servermanager/event/block/SignChangeEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *SignChangeEvent::handlers = new HandlerList;

SignChangeEvent::SignChangeEvent(Block *theBlock, SMPlayer *thePlayer, const std::vector<std::string> &theLines)
	: BlockEvent(theBlock)
{
	player = thePlayer;
	lines = theLines;
	cancel = false;
}

SMPlayer *SignChangeEvent::getPlayer() const
{
	return player;
}

const std::vector<std::string> &SignChangeEvent::getLines() const
{
	return lines;
}

const std::string &SignChangeEvent::getLines(int index) const
{
	if(index < 0 || index >= lines.size())
		return "";

	return lines[index];
}

void SignChangeEvent::setLine(int index, const std::string &line)
{
	if(index < 0 || index >= lines.size())
		return;

	lines[index] = line;
}

bool SignChangeEvent::isCancelled() const
{
	return cancel;
}

void SignChangeEvent::setCancelled(bool cancel)
{
	this->cancel = cancel;
}

HandlerList *SignChangeEvent::getHandlers() const
{
	return handlers;
}

HandlerList *SignChangeEvent::getHandlerList()
{
	return handlers;
}
