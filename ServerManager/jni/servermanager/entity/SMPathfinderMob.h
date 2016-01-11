#pragma once

#include "servermanager/entity/SMMob.h"

class PathfinderMob;

class SMPathfinderMob : public SMMob
{
public:
	SMPathfinderMob(Server *server, PathfinderMob *entity);

	PathfinderMob *getHandle() const;
	void setHandle(PathfinderMob *entity);
};
