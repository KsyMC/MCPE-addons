#pragma once

#include "servermanager/entity/SMAnimal.h"

class Chicken;

class SMChicken : public SMAnimal
{
public:
	SMChicken(Server *server, Chicken *entity);

	Chicken *getHandle() const;
	void setHandle(Chicken *entity);
};
