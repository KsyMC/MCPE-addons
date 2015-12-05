#pragma once

#include "Throwable.h"

class Snowball : public Throwable
{
public:
	virtual void ~Snowball();
	virtual void getEntityTypeId() const;
	virtual void onHit(const HitResult &);
};
