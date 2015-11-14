#pragma once

#include <memory>
#include "../gamemode/GameType.h"

class GameCallbacks;
class SkinInfoFactory;
class Vibration;
class SoundPlayer;
class Whitelist;
class LevelSettings;
class ServerCommandParser;
class GameMode;
class Level;
class NetEventCallback;
class PacketSender;
class RakNetInstance;
class ServerNetworkHandler;
class Player;

// Size : 80
class Minecraft
{
public:
	char filler1[56];					// 0
	ServerCommandParser *commandParser;	// 56

public:
	Minecraft(GameCallbacks &, SkinInfoFactory &, Vibration &, SoundPlayer &, Whitelist const &, std::string const &);
	~Minecraft();
	void createGameMode(GameType, Level &);
	void createLevel(std::string const &, std::string const &, LevelSettings const &);
	ServerCommandParser *getCommandParser();
	GameMode *getGameMode();
	Level *getLevel();
	void *getLevelSource();
	NetEventCallback *getNetEventCallback();
	PacketSender *getPacketSender();
	RakNetInstance *getRakNetInstance();
	std::string getServerName();
	ServerNetworkHandler *getServerNetworkHandler();
	void *getTimer();
	void *getUser();
	void hostMultiplayer(std::unique_ptr<Level>, std::unique_ptr<GameMode>, Player *, std::unique_ptr<NetEventCallback>, bool, int, int);
	void init(std::string const &);
	void initAsDedicatedServer();
	bool isModded();
	bool isOnlineClient();
	void onClientStartedLevel(std::unique_ptr<Level>);
	void resetGameSession();
	void restartMultiplayerHost(int, int);
	void setGameModeReal(GameType);
	void setLeaveGame();
	void setupServerCommands();
	void startClientGame(std::unique_ptr<NetEventCallback>);
	void stopGame();
	void teardown();
	void tick(int, int);
	void update();
};
