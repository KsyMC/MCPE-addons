#include <memory>

#include "SMLevel.h"
#include "../SMPlayer.h"

#include "minecraftpe/Level.h"
#include "minecraftpe/ItemEntity.h"
#include "minecraftpe/Vec3.h"

SMLevel::SMLevel(ServerManager *server, Level *level)
{
	realLevel = level;

	this->server = server;
}

void SMLevel::dropItem(SMPlayer *player, Vec3 const &source, ItemInstance const &item, int delay)
{
	ItemEntity *itemEntity = new ItemEntity(*player->getBlockSource(), source, item, delay);
	itemEntity->setSourceEntity(player->get());

	realLevel->addEntity(std::unique_ptr<Entity>(itemEntity));
}

Level *SMLevel::get() const
{
	return realLevel;
}
