#pragma once

#include <string>

#include "minecraftpe/entity/EntityUniqueID.h"

class Server;
class Entity;

class SMEntity
{
protected:
	Entity *entity;

public:
	SMEntity(Entity *entity);
	~SMEntity();

	int getEntityId() const;

	bool isDead() const;

	EntityUniqueID getUniqueId() const;

	void setNameTag(const std::string &name);
	std::string getNameTag() const;

	void setNameTagVisible(bool flag);
	bool isNameTagVisible();

	Entity *getHandle() const;
};
