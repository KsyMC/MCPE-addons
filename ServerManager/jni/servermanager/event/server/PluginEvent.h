#pragma once

#include "servermanager/event/Event.h"

class Plugin;

class PluginEvent : public Event
{
protected:
	Plugin *plugin;

public:
	PluginEvent(Plugin *plugin);

	Plugin *getPlugin() const;
};
