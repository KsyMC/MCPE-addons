#include <algorithm>

#include "servermanager/plugin/PluginManager.h"
#include "servermanager/Server.h"
#include "servermanager/command/CommandMap.h"
#include "servermanager/command/PluginCommand.h"
#include "servermanager/plugin/PluginBase.h"
#include "servermanager/plugin/RegisteredListener.h"
#include "servermanager/plugin/PluginDescriptionFile.h"
#include "servermanager/event/Event.h"
#include "servermanager/event/HandlerList.h"
#include "servermanager/event/server/PluginEnableEvent.h"
#include "servermanager/event/server/PluginDisableEvent.h"
#include "servermanager/event/player/PlayerJoinEvent.h"
#include "servermanager/event/player/PlayerQuitEvent.h"
#include "servermanager/util/SMUtil.h"
#include "servermanager/version.h"

PluginManager::PluginManager(Server *instance, CommandMap *commandMap)
{
	server = instance;
	this->commandMap = commandMap;
}

void PluginManager::registerPlugin(Plugin *plugin)
{
	prePlugins.push_back(plugin);
}

std::vector<Plugin *> PluginManager::loadPlugins(const std::string &pluginDir)
{
	this->pluginDir = pluginDir;

	std::vector<Plugin *> result;

	std::map<std::string, Plugin *> plugins;
	std::vector<std::string> loadedPlugins;
	std::map<std::string, std::vector<std::string>> dependencies;
	std::map<std::string, std::vector<std::string>> softDependencies;

	for(Plugin *plugin : prePlugins)
	{
		PluginDescriptionFile description(pluginDir + plugin->getPluginDescription());
		std::string name = SMUtil::toLower(description.getName());
		if(name.find(' ') != std::string::npos)
		{

		}
		if(!description.isLoaded() || !name.compare("servermanager") || !name.compare("minecraft") || !name.compare("mojang"))
			continue;

		bool compatible = false;

		for(int smVersion : description.getSMVersions())
			if(smVersion == VERSION_CODE)
				compatible = true;

		if(!compatible)
			continue;

		plugins[description.getName()] = plugin;

		std::vector<std::string> softDependency = description.getSoftDepend();
		if(!softDependency.empty())
		{
			if(softDependencies.find(description.getName()) != softDependencies.end())
				softDependencies[description.getName()].insert(softDependency.end(), softDependency.begin(), softDependency.end());
			else
				softDependencies[description.getName()] = softDependency;
		}

		std::vector<std::string> dependency = description.getDepend();
		if(!dependency.empty())
			dependencies[description.getName()] = dependency;

		std::vector<std::string> loadBefore = description.getLoadBefore();
		if(!loadBefore.empty())
		{
			for(std::string loadBeforeTarget : loadBefore)
			{
				if(softDependencies.find(loadBeforeTarget) != softDependencies.end())
					softDependencies[loadBeforeTarget].push_back(description.getName());
				else
				{
					std::vector<std::string> shortSoftDependency;
					shortSoftDependency.push_back(description.getName());
					softDependencies[loadBeforeTarget] = shortSoftDependency;
				}
			}
		}
	}

	while(!plugins.empty())
	{
		bool missingDependency = true;

		auto pluginIterator = plugins.begin();
		for(; pluginIterator != plugins.end();)
		{
			bool pluginsRemoved = false;
			std::string plugin = pluginIterator->first;

			if(dependencies.find(plugin) != dependencies.end())
			{
				auto dependencyIterator = dependencies[plugin].begin();
				for(; dependencyIterator != dependencies[plugin].end();)
				{
					bool dependencyRemoved = false;
					std::string dependency = *dependencyIterator;

					if(std::find(loadedPlugins.begin(), loadedPlugins.end(), dependency) != loadedPlugins.end())
					{
						dependencyIterator = dependencies[plugin].erase(dependencyIterator);
						dependencyRemoved = true;
					}
					else if(plugins.find(dependency) == plugins.end())
					{
						missingDependency = false;
						pluginIterator = plugins.erase(pluginIterator);
						pluginsRemoved = true;
						softDependencies.erase(plugin);
						dependencies.erase(plugin);
						break;
					}

					if(!dependencyRemoved)
						 ++dependencyIterator;
				}

				if(dependencies.find(plugin) != dependencies.end() && dependencies[plugin].empty())
					dependencies.erase(plugin);
			}
			if(softDependencies.find(plugin) != softDependencies.end())
			{
				auto softDependencyIterator = softDependencies[plugin].begin();
				for(; softDependencyIterator != softDependencies[plugin].end();)
				{
					std::string softDependency = *softDependencyIterator;

					if(plugins.find(softDependency) == plugins.end())
						softDependencyIterator = softDependencies[plugin].erase(softDependencyIterator);
					else
						++softDependencyIterator;
				}

				if(softDependencies[plugin].empty())
					softDependencies.erase(plugin);
			}
			if(!(dependencies.find(plugin) != dependencies.end() ||
					softDependencies.find(plugin) != softDependencies.end()) &&
					plugins.find(plugin) != plugins.end())
			{
				Plugin *p = plugins[plugin];
				pluginIterator = plugins.erase(pluginIterator);
				missingDependency = false;

				result.push_back(loadPlugin(p));
				loadedPlugins.push_back(plugin);
				continue;
			}

			if(!pluginsRemoved)
				++pluginIterator;
		}

		if(missingDependency)
		{
			pluginIterator = plugins.begin();
			for(; pluginIterator != plugins.end(); ++pluginIterator)
			{
				std::string plugin = pluginIterator->first;

				if(dependencies.find(plugin) == dependencies.end())
				{
					softDependencies.erase(plugin);
					missingDependency = false;
					Plugin *p = plugins[plugin];
					pluginIterator = plugins.erase(pluginIterator);

					result.push_back(loadPlugin(p));
					loadedPlugins.push_back(plugin);
					break;
				}
			}

			if(missingDependency)
			{
				softDependencies.clear();
				dependencies.clear();

				auto failedPluginIt = plugins.begin();
				for(; failedPluginIt != plugins.end();)
					failedPluginIt = plugins.erase(failedPluginIt);
			}
		}
	}

	return result;
}

Plugin *PluginManager::loadPlugin(Plugin *plugin)
{
	PluginDescriptionFile *description = new PluginDescriptionFile(pluginDir + plugin->getPluginDescription());
	std::string dataFolder = pluginDir + description->getName() + "/";

	((PluginBase *)plugin)->init(server, description, dataFolder);

	plugins.push_back(plugin);
	lookupNames[plugin->getDescription()->getName()] = plugin;

	return plugin;
}

Plugin *PluginManager::getPlugin(const std::string &name) const
{
	std::string newName = name;
	if(newName.find(' ') != std::string::npos)
	{
		std::string findString = " ";
		newName.replace(newName.find(findString), findString.length(), "_");
	}
	return lookupNames.at(newName);
}

const std::vector<Plugin *> &PluginManager::getPlugins() const
{
	return plugins;
}

bool PluginManager::isPluginEnabled(const std::string &name) const
{
	return isPluginEnabled(getPlugin(name));
}

bool PluginManager::isPluginEnabled(Plugin *plugin) const
{
	auto it = find(plugins.begin(), plugins.end(), plugin);
	if (plugin && it != plugins.end())
		return plugin->isEnabled();
	return false;
}

void PluginManager::enablePlugin(Plugin *plugin)
{
	if(plugin->isEnabled())
		return;

	std::vector<Command *> pluginCommands = parseJsonCommands(plugin);
	if(!pluginCommands.empty())
		commandMap->registerAll(plugin->getDescription()->getName(), pluginCommands);

	((PluginBase *)plugin)->setEnabled(true);

	PluginEnableEvent enableEvent(plugin);
	server->getPluginManager()->callEvent(enableEvent);

	HandlerList::bakeAll();
}

std::vector<Command *> PluginManager::parseJsonCommands(Plugin *plugin)
{
	std::vector<Command *> pluginCmds;

	std::map<std::string, std::map<std::string, PluginDescriptionFile::CommandDescValue>> cmdMap = plugin->getDescription()->getCommands();
	for(auto &it : cmdMap)
	{
		if(it.first.find(':') != std::string::npos)
			continue;

		Command *newCmd = new PluginCommand(it.first, plugin);
		PluginDescriptionFile::CommandDescValue description = it.second["description"];
		PluginDescriptionFile::CommandDescValue usage = it.second["usage"];
		PluginDescriptionFile::CommandDescValue aliases = it.second["aliases"];

		newCmd->setDescription(description.strValue);
		newCmd->setUsage(usage.strValue);

		std::vector<std::string> aliasList;
		if(aliases.isArray)
		{
			for(std::string alias : aliases.arrayValue)
			{
				if(alias.find(':') != std::string::npos)
					continue;

				aliasList.push_back(alias);
			}
		}
		else
		{
			if(aliases.strValue.find(':') == std::string::npos)
				aliasList.push_back(aliases.strValue);
		}
		newCmd->setAliases(aliasList);

		pluginCmds.push_back(newCmd);
	}
	return pluginCmds;
}

void PluginManager::disablePlugins()
{
	std::vector<Plugin *> plugins = getPlugins();
	for(int i = plugins.size() - 1; i >= 0; i--)
		disablePlugin(plugins[i]);
}

void PluginManager::disablePlugin(Plugin *plugin)
{
	if(!plugin->isEnabled())
		return;

	PluginDisableEvent disableEvent(plugin);
	server->getPluginManager()->callEvent(disableEvent);

	((PluginBase *)plugin)->setEnabled(false);

	HandlerList::unregisterAll(plugin);
}

void PluginManager::clearPlugins()
{
	disablePlugins();

	for(Plugin *plugin : getPlugins())
		delete plugin;

	plugins.clear();
	lookupNames.clear();
	HandlerList::unregisterAll();
}

void PluginManager::callEvent(Event &event)
{
	HandlerList *handlers = event.getHandlers();
	std::vector<RegisteredListener *> listeners = handlers->getRegisteredListeners();

	for (RegisteredListener *registration : listeners)
	{
		if (!registration->getPlugin()->isEnabled())
			continue;

		registration->callEvent(event);
	}
}

void PluginManager::registerEvent(EventType type, Listener *listener, std::function<void(Listener *, Event &)> func, Plugin *plugin, EventPriority priority, bool ignoreCancelled)
{
	if(!plugin->isEnabled())
		return;

	auto executor = [func](Listener *listener, Event &event)
	{
		func(listener, event);
	};
	getEventListeners(type)->registerListener(new RegisteredListener(listener, executor, priority, plugin, ignoreCancelled));
}

HandlerList *PluginManager::getEventListeners(EventType type)
{
	switch(type)
	{
	case EventType::PLUGIN_ENABLE:
		return PluginEnableEvent::getHandlerList();
	case EventType::PLUGIN_DISABLE:
		return PluginDisableEvent::getHandlerList();
	case EventType::PLAYER_JOIN:
		return PlayerJoinEvent::getHandlerList();
	case EventType::PLAYER_QUIT:
		return PlayerQuitEvent::getHandlerList();
	}
	return NULL;
}
