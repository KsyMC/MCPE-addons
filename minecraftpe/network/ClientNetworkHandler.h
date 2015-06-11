#pragma once

#include "NetEventCallback.h"
#include "../../raknet/RakNetTypes.h"

class MinecraftClient;
class MultiPlayerLevel;
class IRakNetInstance;
class PacketSender;

class ClientNetworkHandler : public NetEventCallback
{
public:
	//void **vtable;					// 4
	MinecraftClient *minecraftClient;	// 8
	MultiPlayerLevel *multiplayerLevel;	// 12
	IRakNetInstance *raknetInstance;	// 16
	RakNet::RakPeer *rakPeer;			// 20
	RakNet::RakNetGUID guid;			// 24

public:
	ClientNetworkHandler(PacketSender &, MinecraftClient &);
	ClientNetworkHandler(PacketSender &, MinecraftClient &, Level &);
	virtual ~ClientNetworkHandler();
	virtual void onDisconnect(const RakNet::RakNetGUID &);
	virtual void onSwitch(const RakNet::SystemAddress &);
	virtual void handle(const RakNet::RakNetGUID &, PlayStatusPacket *);
	virtual void handle(const RakNet::RakNetGUID &, TextPacket *);
	virtual void handle(const RakNet::RakNetGUID &, TakeItemEntityPacket *);
	virtual void handle(const RakNet::RakNetGUID &, LevelEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, EntityEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, RespawnPacket *);
};
