#include "servermanager/event/Cancellable.h"

Cancellable::~Cancellable()
{
}

bool Cancellable::isCancellable() const
{
	return true;
}
