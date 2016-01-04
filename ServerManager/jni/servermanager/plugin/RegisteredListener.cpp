#include "servermanager/plugin/RegisteredListener.h"
#include "servermanager/event/Event.h"
#include "servermanager/event/Cancellable.h"

RegisteredListener::RegisteredListener(Listener *listener, EventExecutor executor, EventPriority priority, Plugin *plugin, bool ignoreCancelled)
{
	this->listener = listener;
	this->priority = priority;
	this->plugin = plugin;
	this->executor = executor;
	this->ignoreCancelled = ignoreCancelled;
}

Listener *RegisteredListener::getListener() const
{
	return listener;
}

Plugin *RegisteredListener::getPlugin() const
{
	return plugin;
}

EventPriority RegisteredListener::getPriority() const
{
	return priority;
}

bool RegisteredListener::isIgnoringCancelled() const
{
	return ignoreCancelled;
}

void RegisteredListener::callEvent(Event &event)
{
	if(event.isCancellable() && ((Cancellable &)event).isCancelled() && isIgnoringCancelled())
		return;

	executor(listener, event);
}
