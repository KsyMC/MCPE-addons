#pragma once

#include <memory>
#include "NetEventCallback.h"
#include "../level/LevelListener.h"
#include "../gamemode/GameMode.h"

class Minecraft;
class IRakNetInstance;
class Level;

class ServerNetworkHandler : public NetEventCallback, public LevelListener
{
public:
	//void **vtable;					// 4
	Minecraft *minecraft;				// 8
	Level *level;						// 12
	IRakNetInstance *raknetInstance;	// 16

public:
	ServerNetworkHandler(Minecraft *, Level &, const std::unique_ptr<GameMode> &, IRakNetInstance &, PacketSender &, Player *);
	virtual void onPlayerReady(Player &);
	virtual ~ServerNetworkHandler();
	virtual void onNewClient(const RakNet::RakNetGUID &);
	virtual void onDisconnect(const RakNet::RakNetGUID &);
	virtual bool allowIncomingPacketId(const RakNet::RakNetGUID &, int);
	virtual void handle(const RakNet::RakNetGUID &, LoginPacket *);
	virtual void handle(const RakNet::RakNetGUID &, TextPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MoveEntityPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MovePlayerPacket *);
	virtual void handle(const RakNet::RakNetGUID &, RemoveBlockPacket *);
	virtual void handle(const RakNet::RakNetGUID &, EntityEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerEquipmentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerArmorEquipmentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, InteractPacket *);
	virtual void handle(const RakNet::RakNetGUID &, UseItemPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerActionPacket *);
	virtual void handle(const RakNet::RakNetGUID &, DropItemPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerClosePacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetSlotPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetContentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AnimatePacket *);
	virtual void handle(const RakNet::RakNetGUID &, TileEntityDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerInputPacket *);
	virtual void addMoveEntityPacket(const MoveEntityPacketData &);
	virtual void addSetEntityMotionPacket(const Entity &);
	virtual void addBatchPacket(Packet *);
	virtual void sendAndClearBatchedPackets();
	virtual void onPlayerVerified(const RestCallTagData &);
	virtual void onPlayerVerifiedFailed(const RestCallTagData &);
	virtual void onTileChanged(TileSource *, const TilePos &, FullTile, FullTile, int);
	virtual Packet *getAddPacketFromEntity(Entity &);
	virtual void onEntityAdded(Entity &);
	virtual void onEntityRemoved(Entity &);
	virtual void onTileEvent(TileSource *, int, int, int, int, int);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	void _sendLevelData(Player *, const RakNet::RakNetGUID &);
	void allowIncomingConnections(bool);
	void createNewPlayer(const RakNet::RakNetGUID &, LoginPacket *);
	void disallowIncomingConnections();
	void disconnectClient(const RakNet::RakNetGUID &, const std::string &);
	void displayGameMessage(const std::string &, const std::string &);
	Player *getPlayer(const RakNet::RakNetGUID &);
	Player *getPlayer(const RakNet::RakNetGUID &, const EntityUniqueID &);
	unsigned short numberOfConnections();
	void onReady_ClientGeneration(Player *, const RakNet::RakNetGUID &);
	void redistributePacket(Packet *, const RakNet::RakNetGUID &);
	void sendLoginMessageLocal(int, const RakNet::RakNetGUID &, LoginPacket *);
	void sendLoginMessageMCO(int, const RakNet::RakNetGUID &, LoginPacket *);
	Player *getPlayer(const RakNet::RakNetGUID &);
};
