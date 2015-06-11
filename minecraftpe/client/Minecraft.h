#pragma once

#include <memory>
#include "App.h"
#include "settings/Options.h"
#include "../level/Level.h"

class TextureAtlas;
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

// Size : 248
class Minecraft : public App
{
public:
	static TextureAtlas *_itemsTextureAtlas;
	static TextureAtlas *_terrainTextureAtlas;
	static int customDebugId;

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
	Minecraft(int, char **);
	virtual ~Minecraft();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void update();
	virtual void init();
	virtual void teardown();
	virtual void selectLevel(const std::string &, const std::string &, const LevelSettings &);
	virtual void setLevel(std::unique_ptr<Level>, const std::string &, Player *);
	virtual void startFrame();
	virtual void updateGraphics(const Timer &);
	virtual void endFrame();
	virtual void tick(int, int);
	virtual void leaveGame(bool);
	virtual void play(const std::string &, float, float, float, float, float);
	virtual void playUI(const std::string &, float, float);
	virtual void updateSoundLocation(Mob *, float);
	virtual void isServerVisible();
	virtual void sendLocalMessage(const std::string &, const std::string &);
	virtual void getPlayer();
	virtual void onInternetUpdate();
	virtual void createLocalClientNetworkHandler();
	virtual void getSoundPlayer();
	virtual void getVibration();
	void cancelLocateMultiplayer();
	ServerCommandParser *getCommandParser();
	void *getLevelSource();
	PacketSender *getPacketSender();
	std::string getServerName();
	void hostMultiplayer(int, int);
	void init(const std::string &);
	bool isCreativeMode();
	bool isModded();
	bool isOnlineClient();
	void lookForControl();
	void removeAllPlayers();
	void setIsCreativeMode(bool);
	void setLeaveGame();
	void setNetEventCallBack(std::unique_ptr<NetEventCallback>);
};
