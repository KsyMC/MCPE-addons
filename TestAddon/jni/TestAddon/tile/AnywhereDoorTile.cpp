#include "AnywhereDoorTile.h"

int AnywhereDoorTile::getResource(int aux, Random *random)
{
	return 460;
}

void AnywhereDoorTile::use(Player *player, int x, int y, int z)
{
	DoorTile::use(player, x, y, z);
}

void AnywhereDoorTile::attack(Player *player, int x, int y, int z)
{
	DoorTile::attack(player, x, y, z);
}
