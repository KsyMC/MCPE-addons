#include "servermanager/entity/SMEntity.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/level/SMBlockSource.h"
#include "servermanager/entity/SMChicken.h"
#include "servermanager/entity/SMCow.h"
#include "servermanager/entity/SMMushroomCow.h"
#include "servermanager/entity/SMPig.h"
#include "servermanager/entity/SMSheep.h"
#include "servermanager/entity/SMChicken.h"
#include "servermanager/entity/SMZombie.h"
#include "servermanager/entity/SMCreeper.h"
#include "servermanager/entity/SMEnderman.h"
#include "servermanager/entity/SMSkeleton.h"
#include "servermanager/entity/SMBlaze.h"
#include "servermanager/entity/SMWaterMob.h"
#include "servermanager/entity/SMArrow.h"
#include "servermanager/entity/SMBoat.h"
#include "servermanager/entity/SMItemEntity.h"
#include "minecraftpe/entity/Entity.h"
#include "minecraftpe/entity/EntityClassTree.h"

SMEntity::SMEntity(Server *server, Entity *entity)
{
	this->server = server;
	this->entity = entity;

	region = new SMBlockSource(this);
}

SMEntity::~SMEntity()
{
	delete region;
}

SMEntity *SMEntity::getEntity(Server *server, Entity *entity)
{
	EntityType type = entity->getEntityTypeId();
	if(EntityClassTree::isMob(*entity))
	{
		if(EntityClassTree::isPlayer(*entity)) return new SMPlayer(server, (Player *)entity);
		else if(EntityClassTree::isInstanceOf(*entity, EntityType::PATHFINDERMOB))
		{
			if(EntityClassTree::isInstanceOf(*entity, EntityType::ANIMAL))
			{
				if(EntityClassTree::isOfType(type, EntityType::CHICKEN)) return new SMChicken(server, (Chicken *)entity);
				else if(EntityClassTree::isOfType(type, EntityType::COW)) return new SMCow(server, (Cow *)entity);
				else if(EntityClassTree::isOfType(type, EntityType::MUSHROOMCOW)) return new SMMushroomCow(server, (MushroomCow *)entity);
				else if(EntityClassTree::isOfType(type, EntityType::PIG)) return new SMPig(server, (Pig *)entity);
				else if(EntityClassTree::isInstanceOf(*entity, EntityType::TAMABLEANIMAL))
				{
					if(EntityClassTree::isOfType(type, EntityType::WOLF)) return NULL;
					else if(EntityClassTree::isOfType(type, EntityType::OCELOT)) return NULL;
				}
				else if(EntityClassTree::isOfType(type, EntityType::SHEEP)) return new SMSheep(server, (Sheep *)entity);
				else return new SMAnimal(server, (Animal *)entity);
			}
			else if(EntityClassTree::isInstanceOf(*entity, EntityType::MONSTER))
			{
				if(EntityClassTree::isOfType(type, EntityType::ZOMBIE)) return new SMZombie(server, (Zombie *)entity);
				else if(EntityClassTree::isOfType(type, EntityType::GHAST)) return NULL;
				else if(EntityClassTree::isOfType(type, EntityType::PIGZOMBIE)) return NULL;
				else if(EntityClassTree::isOfType(type, EntityType::CREEPER)) return new SMCreeper(server, (Creeper *)entity);
				else if(EntityClassTree::isOfType(type, EntityType::ENDERMAN)) return new SMEnderman(server, (Enderman *)entity);
				else if(EntityClassTree::isOfType(type, EntityType::SILVERFISH)) return NULL;
				else if(EntityClassTree::isOfType(type, EntityType::SKELETON)) return new SMSkeleton(server, (Skeleton *)entity);
				else if(EntityClassTree::isOfType(type, EntityType::BLAZE)) return new SMBlaze(server, (Blaze *)entity);
				else if(EntityClassTree::isOfType(type, EntityType::SPIDER)) return NULL;
				else if(EntityClassTree::isOfType(type, EntityType::CAVESPIDER)) return NULL;
				else if(EntityClassTree::isOfType(type, EntityType::SLIME)) return NULL;
				else if(EntityClassTree::isOfType(type, EntityType::LAVASLIME)) return NULL;
				else return new SMMonster(server, (Monster *)entity);
			}
			else if(EntityClassTree::isInstanceOf(*entity, EntityType::WATERANIMAL))
			{
				if(EntityClassTree::isOfType(type, EntityType::SQUID)) return NULL;
				else return new SMWaterMob(server, (WaterAnimal *)entity);
			}
			else if(EntityClassTree::isOfType(type, EntityType::IRONGOLEM)) return NULL;
			else if(EntityClassTree::isOfType(type, EntityType::SNOWGOLEM)) return NULL;
			else if(EntityClassTree::isOfType(type, EntityType::VILLAGER)) return NULL;
			else return new SMPathfinderMob(server, (PathfinderMob *)entity);
		}
		else if(EntityClassTree::isInstanceOf(*entity, EntityType::A))
		{
			if(EntityClassTree::isOfType(type, EntityType::BAT)) return NULL;
		}
	}
	else if(EntityClassTree::isOfType(type, EntityType::EXPERIENCE_ORB)) return NULL;
	else if(EntityClassTree::isOfType(type, EntityType::ARROW)) return new SMArrow(server, (Arrow *)entity);
	else if(EntityClassTree::isOfType(type, EntityType::BOAT)) return new SMBoat(server, (Boat *)entity);
	else if(EntityClassTree::isOfType(type, EntityType::THROWN_EGG)) return NULL;
	else if(EntityClassTree::isOfType(type, EntityType::SNOWBALL)) return NULL;
	else if(EntityClassTree::isOfType(type, EntityType::THROWN_POTION)) return NULL;
	else if(EntityClassTree::isOfType(type, EntityType::FALLING_BLOCK)) return NULL;
	else if(EntityClassTree::isOfType(type, EntityType::LARGE_FIREBALL)) return NULL;
	else if(EntityClassTree::isOfType(type, EntityType::SMALL_FIREBALL)) return NULL;
	else if(EntityClassTree::isOfType(type, EntityType::DROPPED_ITEM)) return new SMItemEntity(server, (ItemEntity *)entity);
	else if(EntityClassTree::isOfType(type, EntityType::LIGHTNING_BOLT)) return NULL;
	else if(EntityClassTree::isOfType(type, EntityType::EXPERIENCE_ORB)) return NULL;
	else if(EntityClassTree::isOfType(type, EntityType::MINECART)) return NULL;
	else if(EntityClassTree::isOfType(type, EntityType::PAINTING)) return NULL;
	else if(EntityClassTree::isOfType(type, EntityType::PRIMED_TNT)) return NULL;

	return NULL;
}

EntityType SMEntity::getEntityTypeId() const
{
	return entity->getEntityTypeId();
}

bool SMEntity::isDead() const
{
	return !entity->isAlive();
}

EntityUniqueID SMEntity::getUniqueID() const
{
	return entity->getUniqueID();
}

bool SMEntity::teleport(const Location &location, PlayerTeleportEvent::TeleportCause cause)
{
	if(!isDead())
		return false;

	if(entity->isRiding())
		entity->stopRiding(true);

	entity->setPos(location.getPos());

	return true;
}

bool SMEntity::teleport(SMEntity *destination, PlayerTeleportEvent::TeleportCause cause)
{
	return teleport(destination->getLocation(), cause);
}

void SMEntity::setNameTag(const std::string &name)
{
	std::string newName = name;

	if(name.length() > 64)
		newName = newName.erase(64, name.length() - 64);

	entity->setNameTag(name);
}

std::string SMEntity::getNameTag() const
{
	return entity->getNameTag();
}

void SMEntity::setNameTagVisible(bool flag)
{
	entity->setNameTagVisible(flag);
}

bool SMEntity::isNameTagVisible()
{
	return entity->canShowNameTag();
}

float SMEntity::getFallDistance() const
{
	return entity->fallDistance;
}

void SMEntity::setFallDistance(float distance)
{
	entity->fallDistance = distance;
}

SMBlockSource *SMEntity::getRegion() const
{
	return region;
}

Location SMEntity::getLocation() const
{
	return Location(getRegion(), entity->getPos());
}

Location &SMEntity::getLocation(Location &loc) const
{
	loc.setRegion(getRegion());
	loc.setPos(entity->getPos());
	loc.setRotation(entity->getRotation());

	return loc;
}

Vec3 &SMEntity::getVelocity() const
{
	return entity->getVelocity();
}

Server *SMEntity::getServer() const
{
	return server;
}

Entity *SMEntity::getHandle() const
{
	return entity;
}

void SMEntity::setHandle(Entity *entity)
{
	this->entity = entity;
}
