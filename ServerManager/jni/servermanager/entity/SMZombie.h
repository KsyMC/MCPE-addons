#pragma once

#include "servermanager/entity/SMMonster.h"

class Zombie;

class SMZombie : public SMMonster
{
public:
	SMZombie(Server *server, Zombie *entity);

	Zombie *getHandle() const;
	void setHandle(Zombie *entity);
};
