#pragma once

#include "minecraftpe/network/NetEventCallback.h"

class PacketSender;
class MinecraftClient;

// Size : 20
class ClientNetworkHandler : public NetEventCallback
{
public:
	PacketSender *sender;		// 4
	MinecraftClient *client;	// 8
	Level *level;				// 12

public:
	ClientNetworkHandler(PacketSender &, MinecraftClient &);
	ClientNetworkHandler(PacketSender &, MinecraftClient &, Level &);
	virtual ~ClientNetworkHandler();
	virtual void onDisconnect(RakNetGUID const &, string const &);
	virtual void handle(RakNetGUID const &, PlayStatusPacket *);
	virtual void handle(RakNetGUID const &, TextPacket *);
	virtual void handle(RakNetGUID const &, TakeItemEntityPacket *);
	virtual void handle(RakNetGUID const &, SetPlayerGameTypePacket *);
	virtual void handle(RakNetGUID const &, LevelEventPacket *);
	virtual void handle(RakNetGUID const &, EntityEventPacket *);
	virtual void handle(RakNetGUID const &, CraftingDataPacket *);
	virtual void handle(RakNetGUID const &, UpdateAttributesPacket *);
	virtual void handle(RakNetGUID const &, TelemetryEventPacket *);
	virtual void handle(RakNetGUID const &, RespawnPacket *);
};
