#pragma once

#include <string>

#include "servermanager/Location.h"
#include "servermanager/event/player/PlayerTeleportEvent.h"
#include "minecraftpe/entity/EntityUniqueID.h"
#include "minecraftpe/entity/EntityType.h"

class Server;
class Entity;
class SMBlockSource;
class Vec3;

class SMEntity
{
protected:
	Server *server;
	Entity *entity;

	SMBlockSource *region;

public:
	SMEntity(Server *server, Entity *entity);
	virtual ~SMEntity();

	static SMEntity *getEntity(Server *server, Entity *entity);

	EntityType getEntityTypeId() const;

	bool isDead() const;

	EntityUniqueID getUniqueID() const;

	virtual bool teleport(const Location &location, PlayerTeleportEvent::TeleportCause cause = PlayerTeleportEvent::PLUGIN);
	virtual bool teleport(SMEntity *destination, PlayerTeleportEvent::TeleportCause cause = PlayerTeleportEvent::PLUGIN);

	void setNameTag(const std::string &name);
	std::string getNameTag() const;

	void setNameTagVisible(bool flag);
	bool isNameTagVisible();

	float getFallDistance() const;
	void setFallDistance(float distance);

	SMBlockSource *getRegion() const;

	Location getLocation() const;
	Location &getLocation(Location &loc) const;

	Vec3 &getVelocity() const;

	Server *getServer() const;

	Entity *getHandle() const;
	void setHandle(Entity *entity);
};
