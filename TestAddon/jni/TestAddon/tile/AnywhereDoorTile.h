#pragma once

#include "minecraftpe/tile/DoorTile.h"

class AnywhereDoorTile : public DoorTile
{
public:
	AnywhereDoorTile(int id, const Material *material) : DoorTile(id, material) {}
	virtual int getResource(int, Random *);
	virtual void use(Player *, int, int, int);
	virtual void attack(Player *, int, int, int);
};
