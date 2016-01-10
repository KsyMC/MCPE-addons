#pragma once

#include "minecraftpe/network/ClientNetworkHandler.h"
#include "minecraftpe/level/LevelListener.h"
#include "minecraftpe/block/FullBlock.h"

class SoundPlayer;
class EntityLink;
class RakNetInstance;
class SoundPlayer;
class BlockSource;
class BlockPos;
class Entity;

// Size : 112
class LegacyClientNetworkHandler : public ClientNetworkHandler, public LevelListener
{
public:
	//void *vtable;				// 20
	MinecraftClient *client;	// 24
	SoundPlayer *soundPlayer;	// 28
	char filler[4];				// 32
	RakNetInstance *raknet;		// 36
	PacketSender *sender;		// 40
	RakNet::RakPeer *rakPeer;	// 44

	LegacyClientNetworkHandler(MinecraftClient *, RakNetInstance *, PacketSender &, SoundPlayer &);
	virtual void onPlayerReady(Player &);
	virtual ~LegacyClientNetworkHandler();
	virtual void onConnect(const RakNet::RakNetGUID &);
	virtual void onUnableToConnect();
	virtual void handle(const RakNet::RakNetGUID &, DisconnectPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetTimePacket *);
	virtual void handle(const RakNet::RakNetGUID &, StartGamePacket *);
	virtual void handle(const RakNet::RakNetGUID &, AddItemEntityPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AddPaintingPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AddEntityPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AddPlayerPacket *);
	virtual void handle(const RakNet::RakNetGUID &, RemovePlayerPacket *);
	virtual void handle(const RakNet::RakNetGUID &, RemoveEntityPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MoveEntityPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MovePlayerPacket *);
	virtual void handle(const RakNet::RakNetGUID &, UpdateBlockPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ExplodePacket *);
	virtual void handle(const RakNet::RakNetGUID &, BlockEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MobEffectPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MobEquipmentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MobArmorEquipmentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetEntityDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetEntityMotionPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetHealthPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetEntityLinkPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetSpawnPositionPacket *);
	virtual void handle(const RakNet::RakNetGUID &, HurtArmorPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerOpenPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerClosePacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetSlotPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetContentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AdventureSettingsPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AnimatePacket *);
	virtual void handle(const RakNet::RakNetGUID &, BlockEntityDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, FullChunkDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetDifficultyPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ChangeDimensionPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerListPacket *);
	virtual void onBlockChanged(BlockSource &, const BlockPos &, FullBlock, FullBlock, int);
	void _region();
	void getEntityLinksFor(const Entity &);
	void handleEntityLink(const EntityLink &);
	bool isRealmsServer();
	void setRealmsServer();
};
