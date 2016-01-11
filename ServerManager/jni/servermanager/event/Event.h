#pragma once

#include <string>

class HandlerList;

class Event
{
public:
	enum EventResult
	{
		DENY,
		DEFAULT,
		ALLOW
	};

private:
	std::string name;

public:
	Event();
	virtual ~Event();

	std::string getEventName() const;

	virtual bool isCancellable() const;
	virtual HandlerList *getHandlers() const = 0;
};
