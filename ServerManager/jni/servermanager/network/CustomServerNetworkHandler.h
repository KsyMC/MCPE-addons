#pragma once

#include <string>

#include "raknet/RakNetTypes.h"
#include "shared.h"

class ServerNetworkHandler;
class LoginPacket;
class TextPacket;
class MoveEntityPacket;
class MovePlayerPacket;
class RemoveBlockPacket;
class EntityEventPacket;
class MobEquipmentPacket;
class MobArmorEquipmentPacket;
class InteractPacket;
class UseItemPacket;
class PlayerActionPacket;
class DropItemPacket;
class ContainerClosePacket;
class ContainerSetSlotPacket;
class ContainerSetContentPacket;
class CraftingEventPacket;
class AnimatePacket;
class BlockEntityDataPacket;
class PlayerInputPacket;
class SpawnExperienceOrbPacket;
class SMPlayer;

class CustomServerNetworkHandler
{
public:
	FUNCTION_HOOK_H(void, onDisconnect, ServerNetworkHandler *, const RakNet::RakNetGUID &, const std::string &);
	FUNCTION_HOOK_H(void, disconnectClient, ServerNetworkHandler *, const RakNet::RakNetGUID &, const std::string &);

	FUNCTION_HOOK_H(void, allowIncomingPacketId, ServerNetworkHandler *, const RakNet::RakNetGUID &, int);

	FUNCTION_HOOK_H(void, handleLogin, ServerNetworkHandler *, const RakNet::RakNetGUID &, LoginPacket *);
	static void sendLoginMessageLocal(ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, LoginPacket *packet);

	FUNCTION_HOOK_H(void, handleText, ServerNetworkHandler *, const RakNet::RakNetGUID &, TextPacket *);
	FUNCTION_HOOK_H(void, handleMoveEntity, ServerNetworkHandler *, const RakNet::RakNetGUID &, MoveEntityPacket *);
	FUNCTION_HOOK_H(void, handleMovePlayer, ServerNetworkHandler *, const RakNet::RakNetGUID &, MovePlayerPacket *);
	FUNCTION_HOOK_H(void, handleRemoveBlock, ServerNetworkHandler *, const RakNet::RakNetGUID &, RemoveBlockPacket *);
	FUNCTION_HOOK_H(void, handleEntityEvent, ServerNetworkHandler *, const RakNet::RakNetGUID &, EntityEventPacket *);
	FUNCTION_HOOK_H(void, handleMobEquipment, ServerNetworkHandler *, const RakNet::RakNetGUID &, MobEquipmentPacket *);
	FUNCTION_HOOK_H(void, handleMobArmorEquipment, ServerNetworkHandler *, const RakNet::RakNetGUID &, MobArmorEquipmentPacket *);
	FUNCTION_HOOK_H(void, handleInteract, ServerNetworkHandler *, const RakNet::RakNetGUID &, InteractPacket *);
	FUNCTION_HOOK_H(void, handleUseItem, ServerNetworkHandler *, const RakNet::RakNetGUID &, UseItemPacket *);
	FUNCTION_HOOK_H(void, handlePlayerAction, ServerNetworkHandler *, const RakNet::RakNetGUID&, PlayerActionPacket *);
	FUNCTION_HOOK_H(void, handleDropItem, ServerNetworkHandler *, const RakNet::RakNetGUID &, DropItemPacket *);
	FUNCTION_HOOK_H(void, handleContainerClose, ServerNetworkHandler *, const RakNet::RakNetGUID &, ContainerClosePacket *);
	FUNCTION_HOOK_H(void, handleContainerSetSlot, ServerNetworkHandler *, const RakNet::RakNetGUID &, ContainerSetSlotPacket *);
	FUNCTION_HOOK_H(void, handleContainerSetContent, ServerNetworkHandler *, const RakNet::RakNetGUID &, ContainerSetContentPacket *);
	FUNCTION_HOOK_H(void, handleCraftingEvent, ServerNetworkHandler *, const RakNet::RakNetGUID &, CraftingEventPacket *);
	FUNCTION_HOOK_H(void, handleAnimate, ServerNetworkHandler *, const RakNet::RakNetGUID &, AnimatePacket *);
	FUNCTION_HOOK_H(void, handleBlockEntityData, ServerNetworkHandler *, const RakNet::RakNetGUID &, BlockEntityDataPacket *);
	FUNCTION_HOOK_H(void, handlePlayerInput, ServerNetworkHandler *, const RakNet::RakNetGUID &, PlayerInputPacket *);
	FUNCTION_HOOK_H(void, handleSpawnExperienceOrb, ServerNetworkHandler *, const RakNet::RakNetGUID &, SpawnExperienceOrbPacket *);
	FUNCTION_HOOK_H(void, allowIncomingConnections, ServerNetworkHandler *, const std::string &, bool);

	static SMPlayer *_getPlayer(const RakNet::RakNetGUID &guid);

	static void setupHooks();
};
