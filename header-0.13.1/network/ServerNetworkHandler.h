#pragma once

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

	ServerNetworkHandler(GameCallbacks &, Level &, GameMode *, RakNetInstance &, PacketSender &, SkinInfoFactory &, Whitelist const &, Player *);
	virtual void onPlayerReady(Player &);
	virtual ~ServerNetworkHandler();
	virtual void onNewClient(RakNet::RakNetGUID const &);
	virtual void onDisconnect(RakNet::RakNetGUID const &, string const &);
	virtual void allowIncomingPacketId(RakNet::RakNetGUID const &, int);
	virtual void handle(RakNet::RakNetGUID const &, LoginPacket *);
	virtual void handle(RakNet::RakNetGUID const &, TextPacket *);
	virtual void handle(RakNet::RakNetGUID const &, MoveEntityPacket *);
	virtual void handle(RakNet::RakNetGUID const &, MovePlayerPacket *);
	virtual void handle(RakNet::RakNetGUID const &, RemoveBlockPacket *);
	virtual void handle(RakNet::RakNetGUID const &, EntityEventPacket *);
	virtual void handle(RakNet::RakNetGUID const &, MobEquipmentPacket *);
	virtual void handle(RakNet::RakNetGUID const &, MobArmorEquipmentPacket *);
	virtual void handle(RakNet::RakNetGUID const &, InteractPacket *);
	virtual void handle(RakNet::RakNetGUID const &, UseItemPacket *);
	virtual void handle(RakNet::RakNetGUID const &, PlayerActionPacket *);
	virtual void handle(RakNet::RakNetGUID const &, DropItemPacket *);
	virtual void handle(RakNet::RakNetGUID const &, ContainerClosePacket *);
	virtual void handle(RakNet::RakNetGUID const &, ContainerSetSlotPacket *);
	virtual void handle(RakNet::RakNetGUID const &, ContainerSetContentPacket *);
	virtual void handle(RakNet::RakNetGUID const &, CraftingEventPacket *);
	virtual void handle(RakNet::RakNetGUID const &, AnimatePacket *);
	virtual void handle(RakNet::RakNetGUID const &, BlockEntityDataPacket *);
	virtual void handle(RakNet::RakNetGUID const &, PlayerInputPacket *);
	virtual void handle(RakNet::RakNetGUID const &, SpawnExperienceOrbPacket *);
	virtual void addBatchPacket(Packet *);
	virtual void sendAndClearBatchedPackets();
	virtual void onEntityAdded(Entity &);
	virtual void onEntityRemoved(Entity &);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	void _displayGameMessage(string const &, string const &);
	Player *_getPlayer(const RakNet::RakNetGUID &);
	Player *_getPlayer(const RakNet::RakNetGUID &, const EntityUniqueID &);

	void allowIncomingConnections(string const &, bool);
	void disallowIncomingConnections();

	void disconnectClient(RakNet::RakNetGUID const &, string const &);
	unsigned short numberOfConnections();
	void onReady_ClientGeneration(Player *, RakNet::RakNetGUID const &);

	unique_ptr<ServerPlayer> createNewPlayer(RakNet::RakNetGUID const &, LoginPacket *);
	void sendLoginMessageLocal(int, RakNet::RakNetGUID const &, LoginPacket *);
	void _sendAdditionalLevelData(ServerPlayer *, RakNet::RakNetGUID const &);
	void _sendLevelData(ServerPlayer *, RakNet::RakNetGUID const &);
};
