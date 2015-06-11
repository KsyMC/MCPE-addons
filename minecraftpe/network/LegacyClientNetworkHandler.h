#pragma once

#include "ClientNetworkHandler.h"
#include "../level/LevelListener.h"

class SoundPlayer;
class EntityLink;

class LegacyClientNetworkHandler : public ClientNetworkHandler, public LevelListener
{
public:
	LegacyClientNetworkHandler(MinecraftClient *, IRakNetInstance *, PacketSender &, SoundPlayer &);
	virtual void onPlayerReady(Player &);
	virtual ~LegacyClientNetworkHandler();
	virtual void onConnect(const RakNet::RakNetGUID &);
	virtual void onUnableToConnect();
	virtual void onSwitch(const RakNet::SystemAddress &);
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
	virtual void handle(const RakNet::RakNetGUID &, TileEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, MobEffectPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerEquipmentPacket *);
	virtual void handle(const RakNet::RakNetGUID &, PlayerArmorEquipmentPacket *);
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
	virtual void handle(const RakNet::RakNetGUID &, TileEntityDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, FullChunkDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetDifficultyPacket *);
	virtual void onTileChanged(TileSource *, const TilePos &, FullTile, FullTile, int);
	void _region();
	void getEntityLinksFor(const Entity &);
	void handleEntityLink(const EntityLink &);
	bool isRealmsServer();
	void setRealmsServer();
};
