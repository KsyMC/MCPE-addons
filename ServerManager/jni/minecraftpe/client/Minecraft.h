#pragma once

#include <string>
#include <memory>

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
	std::string getServerName();
	void hostMultiplayer(std::unique_ptr<Level>, std::unique_ptr<GameMode>, Player *, std::unique_ptr<NetEventCallback>, bool, int, int);
};
