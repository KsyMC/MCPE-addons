#pragma once

#include "shared.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/network/NetEventCallback.h"
#include "minecraftpe/gamemode/GameMode.h"

class PacketSender;
class Player;
class RakNetInstance;
class ServerCommandParser;

class Minecraft
{
public:
	PacketSender *getPacketSender();
	Level *getLevel();
	RakNetInstance *getRakNetInstance();
	NetEventCallback *getNetEventCallback();
	string getServerName();
	void hostMultiplayer(unique_ptr<Level>, unique_ptr<GameMode>, Player *, unique_ptr<NetEventCallback>, bool, int, int);
};
