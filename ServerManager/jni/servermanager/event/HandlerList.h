#pragma once

#include <vector>
#include <map>

#include "servermanager/event/EventPriority.h"

class Plugin;
class Listener;
class RegisteredListener;

class HandlerList
{
private:
	std::vector<RegisteredListener *> handlers;
	std::map<EventPriority, std::vector<RegisteredListener *>> handlerslots;
	bool needBake;

	static std::vector<HandlerList *> allLists;

public:
	HandlerList();

	static void bakeAll();

	static void unregisterAll();
	static void unregisterAll(Plugin *plugin);
	static void unregisterAll(Listener *listener);

	void registerListener(RegisteredListener *listener);
	void registerAll(std::vector<RegisteredListener *> listeners);

	void unregister(RegisteredListener *listener);
	void unregister(Plugin *plugin);
	void unregister(Listener *listener);

	void bake();

	const std::vector<RegisteredListener *> &getRegisteredListeners();
	std::vector<RegisteredListener *> getRegisteredListeners(Plugin *plugin);

	static const std::vector<HandlerList *> &getHandlerLists();
};
