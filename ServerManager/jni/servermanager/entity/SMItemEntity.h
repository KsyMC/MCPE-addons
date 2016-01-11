#pragma once

#include "servermanager/entity/SMEntity.h"

class ItemEntity;

class SMItemEntity : public SMEntity
{
public:
	SMItemEntity(Server *server, ItemEntity *entity);

	ItemEntity *getHandle() const;
	void setHandle(ItemEntity *entity);
};
