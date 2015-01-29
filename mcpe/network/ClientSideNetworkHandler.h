#ifndef __CLIENTSIDENETWORKHANDLER_H__
#define __CLIENTSIDENETWORKHANDLER_H__

#include "NetEventCallback.h"
#include "../level/LevelListener.h"

namespace RakNet {
	class RakPeer;
}
class MultiPlayerLevel;
class Player;
class TileSource;
class MinecraftClient;
class IRakNetInstance;
class LoginStatusPacket;
class SetTimePacket;
class MessagePacket;
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
class RotateHeadPacket;
class MovePlayerPacket;
class UpdateBlockPacket;
class ExplodePacket;
class LevelEventPacket;
class TileEventPacket;
class EntityEventPacket;
class ChunkDataPacket;
class PlayerEquipmentPacket;
class PlayerArmorEquipmentPacket;
class SetEntityDataPacket;
class SetEntityMotionPacket;
class SetHealthPacket;
class SetEntityLinkPacket;
class SetSpawnPositionPacket;
class InteractPacket;
class HurtArmorPacket;
class ContainerOpenPacket;
class ContainerClosePacket;
class ContainerSetDataPacket;
class ContainerSetSlotPacket;
class ContainerSetContentPacket;
class ChatPacket;
class AdventureSettingsPacket;
class AnimatePacket;
class EntityDataPacket;
class FullChunkDataPacket;
class SetDifficultyPacket;
class RespawnPacket;
struct TilePos;
struct FullTile;

class ClientSideNetworkHandler : public NetEventCallback, public LevelListener {
public:
	//void **vtable;							// 4
	MinecraftClient *_minecraftClient;		// 8
	MultiPlayerLevel *_multiplayerLevel;	// 12
	IRakNetInstance *_raknetInstance;	// 16
	RakNet::RakPeer *_rakPeer;			// 20
	RakNet::RakNetGUID _guid;			// 24

public:
	ClientSideNetworkHandler(MinecraftClient *, IRakNetInstance *);
	virtual void onPlayerReady(Player &);
	virtual ~ClientSideNetworkHandler();
	virtual void onConnect(const RakNet::RakNetGUID &);
	virtual void onUnableToConnect();
	virtual void onDisconnect(const RakNet::RakNetGUID &);
	virtual void handle(const RakNet::RakNetGUID &, LoginStatusPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetTimePacket *);
	virtual void handle(const RakNet::RakNetGUID &, MessagePacket *);
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
	virtual void handle(const RakNet::RakNetGUID &, RotateHeadPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MovePlayerPacket *);
	virtual void handle(const RakNet::RakNetGUID &, UpdateBlockPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ExplodePacket *);
	virtual void handle(const RakNet::RakNetGUID &, LevelEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, TileEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, EntityEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ChunkDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerEquipmentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerArmorEquipmentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetEntityDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetEntityMotionPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetHealthPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetEntityLinkPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetSpawnPositionPacket *);
	virtual void handle(const RakNet::RakNetGUID &, InteractPacket *);
	virtual void handle(const RakNet::RakNetGUID &, HurtArmorPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerOpenPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerClosePacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetSlotPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ContainerSetContentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, ChatPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AdventureSettingsPacket *);
	virtual void handle(const RakNet::RakNetGUID &, AnimatePacket *);
	virtual void handle(const RakNet::RakNetGUID &, EntityDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, FullChunkDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetDifficultyPacket *);
	virtual void handle(const RakNet::RakNetGUID &, RespawnPacket *);
	virtual void onServerFull();
	virtual void onTileChanged(TileSource *, const TilePos &, FullTile, FullTile, int);
	TileSource *_region();
	void clearChunksLoaded();
	bool isChunkLoaded(int, int);
	bool areAllChunksLoaded();
	bool isRealmsServer();
	void setRealmsServer();
};

#endif
