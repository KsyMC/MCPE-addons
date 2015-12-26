#pragma once

#include "shared.h"
#include "minecraftpe/entity/EntityUniqueID.h"

namespace mce
{
class UUID;
};

class Player;
class DisconnectPacket;
class LoginPacket;
class PlayStatusPacket;
class SetTimePacket;
class TextPacket;
class StartGamePacket;
class AddItemEntityPacket;
class AddPaintingPacket;
class TakeItemEntityPacket;
class AddEntityPacket;
class AddMobPacket;
class AddPlayerPacket;
class RemovePlayerPacket;
class RemoveEntityPacket;
class MoveEntityPacket;
class MovePlayerPacket;
class RemoveBlockPacket;
class SetPlayerGameTypePacket;
class UpdateBlockPacket;
class ExplodePacket;
class LevelEventPacket;
class BlockEventPacket;
class EntityEventPacket;
class MobEffectPacket;
class MobEquipmentPacket;
class MobArmorEquipmentPacket;
class SetEntityDataPacket;
class SetEntityMotionPacket;
class SetHealthPacket;
class SetEntityLinkPacket;
class SetSpawnPositionPacket;
class InteractPacket;
class UseItemPacket;
class PlayerActionPacket;
class HurtArmorPacket;
class DropItemPacket;
class ContainerOpenPacket;
class ContainerClosePacket;
class ContainerSetDataPacket;
class ContainerSetSlotPacket;
class ContainerSetContentPacket;
class CraftingDataPacket;
class CraftingEventPacket;
class AdventureSettingsPacket;
class AnimatePacket;
class BlockEntityDataPacket;
class PlayerInputPacket;
class FullChunkDataPacket;
class SetDifficultyPacket;
class ChangeDimensionPacket;
class UpdateAttributesPacket;
class PlayerListPacket;
class TelemetryEventPacket;
class SpawnExperienceOrbPacket;
class Packet;
class RespawnPacket;
class Level;

class NetEventCallback
{
public:
	//void **vtable;	// 0

	virtual void onPlayerReady(Player &);
	virtual ~NetEventCallback();
	virtual void onConnect(RakNet::RakNetGUID const &);
	virtual void onUnableToConnect();
	virtual void onNewClient(RakNet::RakNetGUID const &);
	virtual void onDisconnect(RakNet::RakNetGUID const &, string const &);
	virtual void allowIncomingPacketId(RakNet::RakNetGUID const &, int);
	virtual void handle(RakNet::RakNetGUID const &, DisconnectPacket *);
	virtual void handle(RakNet::RakNetGUID const &, LoginPacket *);
	virtual void handle(RakNet::RakNetGUID const &, PlayStatusPacket *);
	virtual void handle(RakNet::RakNetGUID const &, SetTimePacket *);
	virtual void handle(RakNet::RakNetGUID const &, TextPacket *);
	virtual void handle(RakNet::RakNetGUID const &, StartGamePacket *);
	virtual void handle(RakNet::RakNetGUID const &, AddItemEntityPacket *);
	virtual void handle(RakNet::RakNetGUID const &, AddPaintingPacket *);
	virtual void handle(RakNet::RakNetGUID const &, TakeItemEntityPacket *);
	virtual void handle(RakNet::RakNetGUID const &, AddEntityPacket *);
	virtual void handle(RakNet::RakNetGUID const &, AddMobPacket *);
	virtual void handle(RakNet::RakNetGUID const &, AddPlayerPacket *);
	virtual void handle(RakNet::RakNetGUID const &, RemovePlayerPacket *);
	virtual void handle(RakNet::RakNetGUID const &, RemoveEntityPacket *);
	virtual void handle(RakNet::RakNetGUID const &, MoveEntityPacket *);
	virtual void handle(RakNet::RakNetGUID const &, MovePlayerPacket *);
	virtual void handle(RakNet::RakNetGUID const &, RemoveBlockPacket *);
	virtual void handle(RakNet::RakNetGUID const &, SetPlayerGameTypePacket *);
	virtual void handle(RakNet::RakNetGUID const &, UpdateBlockPacket *);
	virtual void handle(RakNet::RakNetGUID const &, ExplodePacket *);
	virtual void handle(RakNet::RakNetGUID const &, LevelEventPacket *);
	virtual void handle(RakNet::RakNetGUID const &, BlockEventPacket *);
	virtual void handle(RakNet::RakNetGUID const &, EntityEventPacket *);
	virtual void handle(RakNet::RakNetGUID const &, MobEffectPacket *);
	virtual void handle(RakNet::RakNetGUID const &, MobEquipmentPacket *);
	virtual void handle(RakNet::RakNetGUID const &, MobArmorEquipmentPacket *);
	virtual void handle(RakNet::RakNetGUID const &, SetEntityDataPacket *);
	virtual void handle(RakNet::RakNetGUID const &, SetEntityMotionPacket *);
	virtual void handle(RakNet::RakNetGUID const &, SetHealthPacket *);
	virtual void handle(RakNet::RakNetGUID const &, SetEntityLinkPacket *);
	virtual void handle(RakNet::RakNetGUID const &, SetSpawnPositionPacket *);
	virtual void handle(RakNet::RakNetGUID const &, InteractPacket *);
	virtual void handle(RakNet::RakNetGUID const &, UseItemPacket *);
	virtual void handle(RakNet::RakNetGUID const &, PlayerActionPacket *);
	virtual void handle(RakNet::RakNetGUID const &, HurtArmorPacket *);
	virtual void handle(RakNet::RakNetGUID const &, DropItemPacket *);
	virtual void handle(RakNet::RakNetGUID const &, ContainerOpenPacket *);
	virtual void handle(RakNet::RakNetGUID const &, ContainerClosePacket *);
	virtual void handle(RakNet::RakNetGUID const &, ContainerSetDataPacket *);
	virtual void handle(RakNet::RakNetGUID const &, ContainerSetSlotPacket *);
	virtual void handle(RakNet::RakNetGUID const &, ContainerSetContentPacket *);
	virtual void handle(RakNet::RakNetGUID const &, CraftingDataPacket *);
	virtual void handle(RakNet::RakNetGUID const &, CraftingEventPacket *);
	virtual void handle(RakNet::RakNetGUID const &, AdventureSettingsPacket *);
	virtual void handle(RakNet::RakNetGUID const &, AnimatePacket *);
	virtual void handle(RakNet::RakNetGUID const &, BlockEntityDataPacket *);
	virtual void handle(RakNet::RakNetGUID const &, PlayerInputPacket *);
	virtual void handle(RakNet::RakNetGUID const &, FullChunkDataPacket *);
	virtual void handle(RakNet::RakNetGUID const &, SetDifficultyPacket *);
	virtual void handle(RakNet::RakNetGUID const &, ChangeDimensionPacket *);
	virtual void handle(RakNet::RakNetGUID const &, UpdateAttributesPacket *);
	virtual void handle(RakNet::RakNetGUID const &, PlayerListPacket *);
	virtual void handle(RakNet::RakNetGUID const &, TelemetryEventPacket *);
	virtual void handle(RakNet::RakNetGUID const &, SpawnExperienceOrbPacket *);
	virtual void addBatchPacket(Packet *);
	virtual void sendAndClearBatchedPackets();
	virtual void handle(RakNet::RakNetGUID const &, RespawnPacket *);
	Player *findPlayer(Level &, EntityUniqueID);
	Player *findPlayer(Level &, EntityUniqueID, mce::UUID const &);
	Player *findPlayer(Level &, RakNet::RakNetGUID const *);
	Player *findPlayer(Level &, mce::UUID const &);
};
