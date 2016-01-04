#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <functional>

#include "servermanager/event/EventPriority.h"
#include "servermanager/event/EventType.h"

class Server;
class Command;
class CommandMap;
class Event;
class HandlerList;
class Plugin;
class Listener;

class PluginManager
{
private:
	Server *server;
	CommandMap *commandMap;

	std::vector<Plugin *> prePlugins;
	std::vector<Plugin *> plugins;
	std::map<std::string, Plugin *> lookupNames;

	std::string pluginDir;

public:
	PluginManager(Server *instance, CommandMap *commandMap);

	void registerPlugin(Plugin *plugin);
	std::vector<Plugin *> loadPlugins(const std::string &pluginDir);
	Plugin *loadPlugin(Plugin *plugin);

	Plugin *getPlugin(const std::string &name) const;
	const std::vector<Plugin *> &getPlugins() const;

	bool isPluginEnabled(const std::string &name) const;
	bool isPluginEnabled(Plugin *plugin) const;

	void enablePlugin(Plugin *plugin);

private:
	static std::vector<Command *> parseJsonCommands(Plugin *plugin);

public:
	void disablePlugins();
	void disablePlugin(Plugin *plugin);

	void clearPlugins();

	void callEvent(Event &event);
	void registerEvent(EventType type, Listener *listener, std::function<void(Listener *, Event &)> func, Plugin *plugin, EventPriority priority = EventPriority::NORMAL, bool ignoreCancelled = false);

private:
	HandlerList *getEventListeners(EventType type);
};
