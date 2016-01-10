#pragma once

#include <memory>

#include "minecraftpe/network/NetEventCallback.h"
#include "minecraftpe/level/LevelListener.h"
#include "minecraftpe/entity/player/ServerPlayer.h"

class GameCallbacks;
class GameMode;
class RakNetInstance;
class SkinInfoFactory;
class Whitelist;
class PacketSender;
class BatchPacket;
class LevelChunk;
class Entity;

// Size : 72
class ServerNetworkHandler : public NetEventCallback, public LevelListener
{
public:
	//void **vtable;					// 4
	GameCallbacks *callbacks;			// 8
	Level *level;						// 12
	GameMode *gamemode;					// 16
	RakNetInstance *raknet;				// 20
	PacketSender *sender;				// 24
	SkinInfoFactory *skinInfoFactory;	// 28
	Whitelist *whitelist;				// 32
	char filler1[24];					// 36
	bool visible;						// 60
	BatchPacket *batchPacket;			// 64
	Player *player;						// 68

	ServerNetworkHandler(GameCallbacks &, Level &, GameMode *, RakNetInstance &, PacketSender &, SkinInfoFactory &, const Whitelist &, Player *);
	virtual void onPlayerReady(Player &);
	virtual ~ServerNetworkHandler();
	virtual void onNewClient(const RakNet::RakNetGUID &);
	virtual void onDisconnect(const RakNet::RakNetGUID &, const std::string &);
	virtual void allowIncomingPacketId(const RakNet::RakNetGUID &, int);
	virtual void handle(const RakNet::RakNetGUID &, LoginPacket *);
	virtual void handle(const RakNet::RakNetGUID &, TextPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MoveEntityPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MovePlayerPacket *);
	virtual void handle(const RakNet::RakNetGUID &, RemoveBlockPacket *);
	virtual void handle(const RakNet::RakNetGUID &, EntityEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MobEquipmentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MobArmorEquipmentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, InteractPacket *);
	virtual void handle(const RakNet::RakNetGUID &, UseItemPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerActionPacket *);
	virtual void handle(const RakNet::RakNetGUID &, DropItemPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerClosePacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetSlotPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetContentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, CraftingEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AnimatePacket *);
	virtual void handle(const RakNet::RakNetGUID &, BlockEntityDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerInputPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SpawnExperienceOrbPacket *);
	virtual void addBatchPacket(Packet *);
	virtual void sendAndClearBatchedPackets();
	virtual void onEntityAdded(Entity &);
	virtual void onEntityRemoved(Entity &);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	void _displayGameMessage(const std::string &, const std::string &);
	Player *_getPlayer(const RakNet::RakNetGUID &);
	Player *_getPlayer(const RakNet::RakNetGUID &, const EntityUniqueID &);

	void allowIncomingConnections(const std::string &, bool);
	void disallowIncomingConnections();

	void disconnectClient(const RakNet::RakNetGUID &, const std::string &);
	unsigned short numberOfConnections();
	void onReady_ClientGeneration(Player *, const RakNet::RakNetGUID &);

	std::unique_ptr<ServerPlayer> createNewPlayer(const RakNet::RakNetGUID &, LoginPacket *);
	void sendLoginMessageLocal(int, const RakNet::RakNetGUID &, LoginPacket *);
	void _sendAdditionalLevelData(ServerPlayer *, const RakNet::RakNetGUID &);
	void _sendLevelData(ServerPlayer *, const RakNet::RakNetGUID &);
};
