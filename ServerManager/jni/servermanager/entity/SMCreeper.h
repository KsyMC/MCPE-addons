#pragma once

#include "servermanager/entity/SMMob.h"

class Creeper;

class SMCreeper : public SMMob
{
public:
	SMCreeper(Server *server, Creeper *entity);

	bool isPowered() const;
	void setPowered(bool powered);

	Creeper *getHandle() const;
	void setHandle(Creeper *entity);
};
