#include "servermanager/event/Event.h"

Event::Event()
{
}

Event::~Event()
{
}

std::string Event::getEventName() const
{
	return name;
}

bool Event::isCancellable() const
{
	return false;
}
