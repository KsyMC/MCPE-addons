#include <algorithm>

#include "servermanager/event/HandlerList.h"
#include "servermanager/plugin/RegisteredListener.h"

std::vector<HandlerList *> HandlerList::allLists;

HandlerList::HandlerList()
{
	handlerslots[EventPriority::LOWEST] = {};
	handlerslots[EventPriority::LOW] = {};
	handlerslots[EventPriority::NORMAL] = {};
	handlerslots[EventPriority::HIGH] = {};
	handlerslots[EventPriority::HIGHEST] = {};
	handlerslots[EventPriority::MONITOR] = {};
	needBake = true;

	allLists.push_back(this);
}

void HandlerList::bakeAll()
{
	for(HandlerList *h : allLists)
		h->bake();
}

void HandlerList::unregisterAll()
{
	for(HandlerList *h : allLists)
	{
		for(auto &it : h->handlerslots)
		{
			for(RegisteredListener *listener : it.second)
				delete listener;

			it.second.clear();
		}
		h->needBake = true;
	}
}

void HandlerList::unregisterAll(Plugin *plugin)
{
	for(HandlerList *h : allLists)
		h->unregister(plugin);
}

void HandlerList::unregisterAll(Listener *listener)
{
	for(HandlerList *h : allLists)
		h->unregister(listener);
}

void HandlerList::registerListener(RegisteredListener *listener)
{
	std::vector<RegisteredListener *> list = handlerslots[listener->getPriority()];
	if(std::find(list.begin(), list.end(), listener) == list.end())
	{
		needBake = true;
		handlerslots[listener->getPriority()].push_back(listener);
	}
}

void HandlerList::registerAll(std::vector<RegisteredListener *> listeners)
{
	for(RegisteredListener *listener : listeners)
		registerListener(listener);
}

void HandlerList::unregister(RegisteredListener *listener)
{
	std::vector<RegisteredListener *> list = handlerslots[listener->getPriority()];
	auto it = std::find(list.begin(), list.end(), listener);
	if(it != list.end())
	{
		delete listener;
		list.erase(it);
		needBake = true;
	}
}

void HandlerList::unregister(Plugin *plugin)
{
	for(auto &listIter : handlerslots)
	{
		for(auto it = listIter.second.begin(); it != listIter.second.end();)
		{
			RegisteredListener *listener = *it;
			if(listener->getPlugin() == plugin)
			{
				delete listener;
				it = listIter.second.erase(it);
				needBake = true;
			}
			else
				++it;
		}
	}
}

void HandlerList::unregister(Listener *listener)
{
	bool changed = false;
	for(auto &listIter : handlerslots)
	{
		for(auto it = listIter.second.begin(); it != listIter.second.end();)
		{
			RegisteredListener *registeredListener = *it;
			if(registeredListener->getListener() == listener)
			{
				delete registeredListener;
				it = listIter.second.erase(it);
				needBake = true;
			}
			else
				++it;
		}
	}
}

void HandlerList::bake()
{
	if(!needBake)
		return;

	handlers.clear();
	needBake = false;

	for(auto &it : handlerslots)
		for(RegisteredListener *listener : it.second)
			handlers.push_back(listener);
}

const std::vector<RegisteredListener *> &HandlerList::getRegisteredListeners()
{
	while(needBake)
		bake();

	return handlers;
}

std::vector<RegisteredListener *> HandlerList::getRegisteredListeners(Plugin *plugin)
{
	std::vector<RegisteredListener *> listeners;

	for(HandlerList *h : allLists)
		for(auto &it : h->handlerslots)
			for(RegisteredListener *listener : it.second)
				if(listener->getPlugin() == plugin)
					listeners.push_back(listener);
}

const std::vector<HandlerList *> &HandlerList::getHandlerLists()
{
	return allLists;
}
