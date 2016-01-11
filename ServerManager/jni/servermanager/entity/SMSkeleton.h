#pragma once

#include "servermanager/entity/SMMob.h"

class Skeleton;

class SMSkeleton : public SMMob
{
public:
	SMSkeleton(Server *server, Skeleton *entity);

	Skeleton *getHandle() const;
	void setHandle(Skeleton *entity);
};
