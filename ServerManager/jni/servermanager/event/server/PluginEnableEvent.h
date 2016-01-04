#pragma once

#include "servermanager/event/server/PluginEvent.h"

class PluginEnableEvent : public PluginEvent
{
private:
	static HandlerList *handlers;

public:
	PluginEnableEvent(Plugin *plugin);

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
