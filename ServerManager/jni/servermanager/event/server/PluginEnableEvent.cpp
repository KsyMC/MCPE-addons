#include "servermanager/event/server/PluginEnableEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *PluginEnableEvent::handlers = new HandlerList;

PluginEnableEvent::PluginEnableEvent(Plugin *plugin)
	: PluginEvent(plugin)
{
}

HandlerList *PluginEnableEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PluginEnableEvent::getHandlerList()
{
	return handlers;
}
