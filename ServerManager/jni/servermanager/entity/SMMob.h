#pragma once

#include "servermanager/entity/SMEntity.h"

class Mob;

class SMMob : public SMEntity
{
public:
	SMMob(Server *server, Mob *entity);

	int getHealth() const;
	void setHealth(int);

	int getMaxHealth() const;

	bool teleport(const Location &location, PlayerTeleportEvent::TeleportCause cause = PlayerTeleportEvent::PLUGIN);

	virtual float getEyeHeight();
	virtual float getEyeHeight(bool ignoreSneaking);

	Mob *getHandle() const;
	void setHandle(Mob *entity);
};
