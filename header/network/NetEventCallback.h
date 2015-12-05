#pragma once

namespace RakNet
{
	class RakNetGUID;
	class RakPeer;
	class SystemAddress;
}

class Level;
class Player;
class Entity;
class Mob;
class Packet;
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
class UpdateBlockPacket;
class ExplodePacket;
class LevelEventPacket;
class TileEventPacket;
class EntityEventPacket;
class MobEffectPacket;
class PlayerEquipmentPacket;
class PlayerArmorEquipmentPacket;
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
class ContainerAckPacket;
class ContainerSetDataPacket;
class ContainerSetSlotPacket;
class ContainerSetContentPacket;
class AdventureSettingsPacket;
class AnimatePacket;
class TileEntityDataPacket;
class PlayerInputPacket;
class FullChunkDataPacket;
class SetDifficultyPacket;
class MoveEntityPacketData;
class RespawnPacket;
class RestCallTagData;
class EntityUniqueID;

class NetEventCallback
{
public:
	//void **vtable;	// 0

public:
	virtual void onPlayerReady(Player &);
	virtual ~NetEventCallback();
	virtual void onConnect(const RakNet::RakNetGUID &);
	virtual void onUnableToConnect();
	virtual void onNewClient(const RakNet::RakNetGUID &);
	virtual void onDisconnect(const RakNet::RakNetGUID &);
	virtual void onSwitch(const RakNet::SystemAddress &);
	virtual bool allowIncomingPacketId(const RakNet::RakNetGUID &, int);
	virtual void handle(const RakNet::RakNetGUID &, DisconnectPacket *);
	virtual void handle(const RakNet::RakNetGUID &, LoginPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayStatusPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetTimePacket *);
	virtual void handle(const RakNet::RakNetGUID &, TextPacket *);
	virtual void handle(const RakNet::RakNetGUID &, StartGamePacket *);
	virtual void handle(const RakNet::RakNetGUID &, AddItemEntityPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AddPaintingPacket *);
	virtual void handle(const RakNet::RakNetGUID &, TakeItemEntityPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AddEntityPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AddMobPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AddPlayerPacket *);
	virtual void handle(const RakNet::RakNetGUID &, RemovePlayerPacket *);
	virtual void handle(const RakNet::RakNetGUID &, RemoveEntityPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MoveEntityPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MovePlayerPacket *);
	virtual void handle(const RakNet::RakNetGUID &, RemoveBlockPacket *);
	virtual void handle(const RakNet::RakNetGUID &, UpdateBlockPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ExplodePacket *);
	virtual void handle(const RakNet::RakNetGUID &, LevelEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, TileEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, EntityEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MobEffectPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerEquipmentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerArmorEquipmentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetEntityDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetEntityMotionPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetHealthPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetEntityLinkPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetSpawnPositionPacket *);
	virtual void handle(const RakNet::RakNetGUID &, InteractPacket *);
	virtual void handle(const RakNet::RakNetGUID &, UseItemPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerActionPacket *);
	virtual void handle(const RakNet::RakNetGUID &, HurtArmorPacket *);
	virtual void handle(const RakNet::RakNetGUID &, DropItemPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerOpenPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerClosePacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerAckPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetSlotPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetContentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AdventureSettingsPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AnimatePacket *);
	virtual void handle(const RakNet::RakNetGUID &, TileEntityDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerInputPacket *);
	virtual void handle(const RakNet::RakNetGUID &, FullChunkDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetDifficultyPacket *);
	virtual void addMoveEntityPacket(const MoveEntityPacketData &);
	virtual void addSetEntityMotionPacket(const Entity &);
	virtual void addBatchPacket(Packet *);
	virtual void sendAndClearBatchedPackets();
	virtual void handle(const RakNet::RakNetGUID &, RespawnPacket *);
	virtual void onPlayerVerified(const RestCallTagData &);
	virtual void onPlayerVerifiedFailed(const RestCallTagData &);
	Player *findPlayer(Level &, EntityUniqueID);
	Player *findPlayer(Level &, EntityUniqueID, const RakNet::RakNetGUID *);
	Player *findPlayer(Level &, const RakNet::RakNetGUID *);
};