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
	virtual void onDisconnect(const RakNet::RakNetGUID &, const std::string &);
	virtual void handle(const RakNet::RakNetGUID &, PlayStatusPacket *);
	virtual void handle(const RakNet::RakNetGUID &, TextPacket *);
	virtual void handle(const RakNet::RakNetGUID &, TakeItemEntityPacket *);
	virtual void handle(const RakNet::RakNetGUID &, SetPlayerGameTypePacket *);
	virtual void handle(const RakNet::RakNetGUID &, LevelEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, EntityEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, CraftingDataPacket *);
	virtual void handle(const RakNet::RakNetGUID &, UpdateAttributesPacket *);
	virtual void handle(const RakNet::RakNetGUID &, TelemetryEventPacket *);
	virtual void handle(const RakNet::RakNetGUID &, RespawnPacket *);
};
