#pragma once

#include "servermanager/event/Event.h"
#include "minecraftpe/entity/EntityType.h"

class SMEntity;

class SMEntityEvent : public Event
{
protected:
	SMEntity *entity;

public:
	SMEntityEvent(SMEntity *what);

	SMEntity *getEntity() const;
	EntityType getEntityType() const;
};
