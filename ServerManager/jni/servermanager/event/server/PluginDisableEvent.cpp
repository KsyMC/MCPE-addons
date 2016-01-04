#include "servermanager/event/server/PluginDisableEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *PluginDisableEvent::handlers = new HandlerList;

PluginDisableEvent::PluginDisableEvent(Plugin *plugin)
	: PluginEvent(plugin)
{
}

HandlerList *PluginDisableEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PluginDisableEvent::getHandlerList()
{
	return handlers;
}
