#pragma once

#include <memory>

#include "servermanager/event/EventPriority.h"
#include "servermanager/event/EventExecutor.h"

class Listener;
class Plugin;
class Event;

class RegisteredListener
{
private:
	Listener *listener;
	EventPriority priority;
	Plugin *plugin;
	EventExecutor executor;
	bool ignoreCancelled;

public:
	RegisteredListener(Listener *listener, EventExecutor executor, EventPriority priority, Plugin *plugin, bool ignoreCancelled);

	Listener *getListener() const;
	Plugin *getPlugin() const;
	EventPriority getPriority() const;
	bool isIgnoringCancelled() const;

	void callEvent(Event &event);
};
