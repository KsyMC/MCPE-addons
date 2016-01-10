#pragma once

#include "minecraftpe/entity/EntityType.h"

class Entity;

class EntityClassTree
{
public:
	static char getEntityTypeIdLegacy(EntityType);
	static EntityType getMobCategory(EntityType);
	static bool isInstanceOf(const Entity &, EntityType);
	static bool isMob(const Entity &);
	static bool isMob(EntityType);
	static bool isHangingEntity(const Entity &);
	static bool isItemEntity(const Entity &);
	static bool isPlayer(const Entity &);
	static bool isMobLegacy(EntityType);
	static bool isOfType(EntityType, EntityType);
	static bool isTypeInstanceOf(EntityType, EntityType);
};

std::string EntityTypeToString(EntityType);
EntityType EntityTypeFromString(const std::string &);
