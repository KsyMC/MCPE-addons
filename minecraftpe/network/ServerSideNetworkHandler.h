#pragma once

#include "minecraftpe/network/NetEventCallback.h"
#include "minecraftpe/level/LevelListener.h"

class ServerSideNetworkHandler : public NetEventCallback, LevelListener {
public:
	//void **vtable;					// 4
	Minecraft *_minecraft;				// 8
	Level *_level;						// 12
	IRakNetInstance *_raknetInstance;	// 16

public:
	ServerSideNetworkHandler(Minecraft *, IRakNetInstance *);
	virtual void onPlayerReady(Player &);
	virtual ~ServerSideNetworkHandler();
	virtual void onNewClient(const RakNet::RakNetGUID &);
	virtual void onDisconnect(const RakNet::RakNetGUID &);
	virtual bool allowIncomingPacketId(const RakNet::RakNetGUID &, int);
	virtual void handle(const RakNet::RakNetGUID &, LoginPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MessagePacket *);
	virtual void handle(const RakNet::RakNetGUID &, MovePlayerPacket *);
	virtual void handle(const RakNet::RakNetGUID &, RemoveBlockPacket *);
	virtual void handle(const RakNet::RakNetGUID &, EntityEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerEquipmentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerArmorEquipmentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetHealthPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetEntityLinkPacket *);
	virtual void handle(const RakNet::RakNetGUID &, InteractPacket *);
	virtual void handle(const RakNet::RakNetGUID &, UseItemPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerActionPacket *);
	virtual void handle(const RakNet::RakNetGUID &, DropItemPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerClosePacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetSlotPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetContentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AnimatePacket *);
	virtual void handle(const RakNet::RakNetGUID &, EntityDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerInputPacket *);
	virtual void addMoveEntityPacket(const Entity *);
	virtual void addSetEntityMotionPacket(const Entity *);
	virtual void addRotateHeadPacket(const Mob *);
	virtual void sendAndClearBatchedPackets();
	virtual void handle(const RakNet::RakNetGUID &, RespawnPacket *);
	virtual void onPlayerVerified(const void *); // TODO RestCallTagData
	virtual void onPlayerVerifiedFailed(const void *); // TODO RestCallTagData
	virtual void onTileChanged(TileSource *, const TilePos &, FullTile, FullTile, int);
	virtual Packet *getAddPacketFromEntity(Entity *);
	virtual void onEntityAdded(Entity &);
	virtual void onEntityRemoved(Entity &);
	virtual void levelEvent(Mob *, int, int, int, int, int);
	virtual void onTileEvent(TileSource *, int, int, int, int, int);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	void _sendLevelData(Player *, const RakNet::RakNetGUID &);
	void allowIncomingConnections(bool);
	void redistributePacket(Packet *, const RakNet::RakNetGUID &);
	void displayGameMessage(const std::string &, const std::string &);
	void createNewPlayer(const RakNet::RakNetGUID &, LoginPacket *);
	void sendLoginMessageLocal(int, const RakNet::RakNetGUID &, LoginPacket *);
	void sendLoginMessageMCO(int, const RakNet::RakNetGUID &, LoginPacket *);
	Player *getPlayer(const RakNet::RakNetGUID &);
	unsigned short numberOfConnections();
};
