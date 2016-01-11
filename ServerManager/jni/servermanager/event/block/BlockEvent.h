#pragma once

#include "servermanager/event/Event.h"

class Block;

class BlockEvent : public Event
{
protected:
	Block *block;

public:
	BlockEvent(Block *theBlock);

	Block *getBlock() const;
};
