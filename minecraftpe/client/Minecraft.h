#pragma once

#include <memory>
#include "settings/Options.h"
#include "../level/Level.h"

class ServerCommandParser;
class NetEventCallback;
class GameMode;
class PacketSender;
class RakNetInstance;
class LevelSettings;
class Timer;
class Mob;
class LocalPlayer;
class ClientSideNetworkHandler;
class ExternalFileLevelStorageSource;
class GameCallbacks;
class SkinInfoFactory;
class Whitelist;

// Size : 248
class Minecraft
{
public:
	char filler1[4];					// 28
	int displayWidth;					// 32
	int displayHeight;					// 36
	char filler2[32];					// 40
	std::string serverName;				// 72
	char filler3[36];					// 76
	ServerCommandParser *commandParser;	// 112
	char filler4[104];					// 116
	NetEventCallback *netEventCallback;	// 220
	GameMode *gameMode;					// 224
	PacketSender *packetSender;			// 228
	char filler5[4];					// 232
	RakNetInstance *raknetInstance;		// 236
	char filler6[4];					// 240
	Level *level;						// 244

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
