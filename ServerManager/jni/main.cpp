#include <jni.h>
#include <dlfcn.h>

#include "Substrate.h"
#include "dl_internal.h"
#include "tinyhook.h"
#include "shared.h"

#include "minecraftpe/AppPlatform.h"
#include "minecraftpe/Options.h"
#include "minecraftpe/Minecraft.h"
#include "minecraftpe/MinecraftClient.h"
#include "minecraftpe/RakNetInstance.h"
#include "minecraftpe/ServerNetworkHandler.h"
#include "minecraftpe/OptionsGroup.h"
#include "minecraftpe/OptionsScreen.h"
#include "minecraftpe/ChatScreen.h"
#include "minecraftpe/StartMenuScreen.h"
#include "minecraftpe/LoginPacket.h"
#include "minecraftpe/TextPacket.h"
#include "minecraftpe/ServerPlayer.h"
#include "minecraftpe/LocalPlayer.h"
#include "minecraftpe/I18n.h"
#include "raknet/RakPeer.h"

#include "servermanager/ServerManager.h"
#include "servermanager/SMLocalPlayer.h"
#include "servermanager/utils/SMOptions.h"
#include "servermanager/utils/SMList.h"
#include "servermanager/utils/SMUtil.h"

Options::Option Options::Option::MOTD;
Options::Option Options::Option::SERVER_PORT;
Options::Option Options::Option::MAX_PLAYERS;
Options::Option Options::Option::SHOW_IP;
Options::Option Options::Option::ALLOW_ONLY_WIFI_IP;

static ServerManager *server;

static void (*ServerNetworkHandler$handleLoginPacket_real)(ServerNetworkHandler *, const RakNet::RakNetGUID &, LoginPacket *);
static void ServerNetworkHandler$handleLoginPacket_hook(ServerNetworkHandler *_this, const RakNet::RakNetGUID &guid, LoginPacket *packet)
{
	if(!_this->enable || _this->_getPlayer(guid))
		return;

	RakNet::SystemAddress systemAddress = _this->rakNetInstance->getPeer()->GetSystemAddressFromGuid(guid);

	SMPlayer *newPlayer = new SMPlayer(server, _this->packetSender, guid, systemAddress.ToString(false, '|'), systemAddress.GetPort());
	server->addPlayer(newPlayer);

	newPlayer->handleDataPacket(packet);
}

static void (*ServerNetworkHandler$handleTextPacket_real)(ServerNetworkHandler *, RakNet::RakNetGUID const &, TextPacket *);
static void ServerNetworkHandler$handleTextPacket_hook(ServerNetworkHandler *_this, RakNet::RakNetGUID const &guid, TextPacket *packet)
{
	SMPlayer *player = server->getPlayerExact(_this->_getPlayer(guid)->username);
	if(player)
		player->handleDataPacket(packet);
}

static void (*ServerNetworkHandler$onDisconnect_real)(ServerNetworkHandler *, RakNet::RakNetGUID const &, std::string const &);
static void ServerNetworkHandler$onDisconnect_hook(ServerNetworkHandler *_this, RakNet::RakNetGUID const &guid, std::string const &message)
{
	if(!_this->_getPlayer(guid))
		return;

	SMPlayer *player = server->getPlayerExact(_this->_getPlayer(guid)->username);
	if(player)
		server->removePlayer(player);

	ServerNetworkHandler$onDisconnect_real(_this, guid, message);
}

static void (*MinecraftClient$init_real)(MinecraftClient *);
static void MinecraftClient$init_hook(MinecraftClient *_this)
{
	MinecraftClient$init_real(_this);
}

static bool (*Touch$StartMenuScreen$handleBackEvent_real)(Touch::StartMenuScreen *, bool);
static bool Touch$StartMenuScreen$handleBackEvent_hook(Touch::StartMenuScreen *_this, bool b1)
{
	delete server;

	return Touch$StartMenuScreen$handleBackEvent_real(_this, b1);
}

static void (*MinecraftClient$leaveGame_real)(MinecraftClient *, bool);
static void MinecraftClient$leaveGame_hook(MinecraftClient *_this, bool b1)
{
	MinecraftClient$leaveGame_real(_this, b1);

	if(server->isStarted())
		server->leaveServer();
}

static void (*LocalPlayer$tickWorld_real)(LocalPlayer *);
static void LocalPlayer$tickWorld_hook(LocalPlayer *_this)
{
	LocalPlayer$tickWorld_real(_this);

	if(!server->isStarted())
		server->startServer(_this);
}

static std::string (*Minecraft$getServerName_real)(Minecraft *);
static std::string Minecraft$getServerName_hook(Minecraft *_this)
{
	return server->getOptions()->getServerName();
}

static void (*ChatScreen$sendChatMessage_real)(ChatScreen *);
static void ChatScreen$sendChatMessage_hook(ChatScreen *_this)
{
	if(server->isOnlineClient())
	{
		ChatScreen$sendChatMessage_real(_this);
		return;
	}

	if(_this->message[0] == '/')
	{
		server->dispatchCommand(server->getHost(), _this->message.erase(0, 1));

		_this->message = "";

		if(AppPlatform::mSingleton->isKeyboardVisible())
			AppPlatform::mSingleton->updateTextBoxText("");
	}
	else
		ChatScreen$sendChatMessage_real(_this);
}

static void (*RakNetInstance$_startupIfNeeded_real)(RakNetInstance *, unsigned short, int);
static void RakNetInstance$_startupIfNeeded_hook(RakNetInstance *_this, unsigned short port, int connections)
{
	SMOptions *options = server->getOptions();
	RakNetInstance$_startupIfNeeded_real(_this, options->getServerPort(), options->getServerPlayers());
}

static void (*RakNetInstance$host_real)(RakNet::RakPeer *, std::string const &name, int port, int connections);
static void RakNetInstance$host_hook(RakNet::RakPeer *_this, std::string const &name, int port, int connections)
{
	SMOptions *options = server->getOptions();
	RakNetInstance$host_real(_this, name, options->getServerPort(), options->getServerPlayers());
}

static void (*ServerPlayer$normalTick_real)(ServerPlayer *);
static void ServerPlayer$normalTick_hook(ServerPlayer *_this)
{
	ServerPlayer$normalTick_real(_this);

	SMPlayer *player = server->getPlayerExact(_this->username);
	if(player)
		player->onUpdate();
}

static void (*OptionsScreen$_generateOptionScreensDefault_real)(OptionsScreen *);
static void OptionsScreen$_generateOptionScreensDefault_hook(OptionsScreen *_this)
{
	OptionsScreen$_generateOptionScreensDefault_real(_this);

	std::string groupName = SMUtil::format("SM V%s / Made by %s", VERSION, MADE_BY);

	OptionsGroup *pMainGroup = _this->vectorPanes[0]->createOptionsGroup(groupName, true);
	pMainGroup->addOptionItem(Options::Option::MOTD, *_this->client);
	pMainGroup->addOptionItem(Options::Option::SERVER_PORT, *_this->client);
	pMainGroup->addOptionItem(Options::Option::MAX_PLAYERS, *_this->client);
	pMainGroup->addOptionItem(Options::Option::SHOW_IP, *_this->client);
	pMainGroup->addOptionItem(Options::Option::ALLOW_ONLY_WIFI_IP, *_this->client);
}

static void (*Options$setString_real)(Options *, const Options::Option *, const std::string &);
static void Options$setString_hook(Options * _this, const Options::Option *option, const std::string &value)
{
	SMOptions *options = server->getOptions();

	if(option == &Options::Option::MOTD) options->setServerName(value);
	else if(option == &Options::Option::SERVER_PORT)
		options->setServerPort((unsigned short)SMUtil::toInt(value));
	else if(option == &Options::Option::MAX_PLAYERS)
		options->setServerPlayers(SMUtil::toInt(value));
	else Options$setString_real(_this, option, value);
}

static std::string (*Options$getStringValue_real)(Options *, const Options::Option *);
static std::string Options$getStringValue_hook(Options * _this, const Options::Option *option)
{
	SMOptions *options = server->getOptions();

	if(option == &Options::Option::MOTD) return options->getServerName();
	else if(option == &Options::Option::SERVER_PORT) return SMUtil::toString(options->getServerPort());
	else if(option == &Options::Option::MAX_PLAYERS) return SMUtil::toString(options->getServerPlayers());
	else return Options$getStringValue_real(_this, option);
}

static bool (*Options$getBooleanValue_real)(Options *, const Options::Option *);
static bool Options$getBooleanValue_hook(Options * _this, const Options::Option *option)
{
	SMOptions *options = server->getOptions();

	if(option == &Options::Option::SHOW_IP) return options->isShowIp();
	else if(option == &Options::Option::ALLOW_ONLY_WIFI_IP) return options->isAllowOnlyWifiIp();
	else return Options$getBooleanValue_real(_this, option);
}

static void (*Options$toggle_real)(Options *, const Options::Option *, int);
static void Options$toggle_hook(Options * _this, const Options::Option *option, int value)
{
	SMOptions *options = server->getOptions();

	if(option == &Options::Option::SHOW_IP) options->toggleShowIp();
	else if(option == &Options::Option::ALLOW_ONLY_WIFI_IP) options->toggleAllowOnlyWifiIp();
	else return Options$toggle_real(_this, option, value);
}

static void (*Options$save_real)(Options *);
static void Options$save_hook(Options * _this)
{
	Options$save_real(_this);
	server->getOptions()->save();
}

static void (*Options$_load_real)(Options *);
static void Options$_load_hook(Options * _this)
{
	Options$_load_real(_this);

	std::string filePath = _this->filepath;
	std::string findString = "options.txt";
	filePath.replace(filePath.find(findString), findString.length(), "");

	server->load(filePath);
}

static void initOptions()
{
	Options::Option::MOTD.type = Options::Option::TYPE_TEXT;
	Options::Option::MOTD.desc = "motd";

	Options::Option::SERVER_PORT.type = Options::Option::TYPE_TEXT;
	Options::Option::SERVER_PORT.desc = "server-port";

	Options::Option::MAX_PLAYERS.type = Options::Option::TYPE_TEXT;
	Options::Option::MAX_PLAYERS.desc = "max-players";

	Options::Option::SHOW_IP.type = Options::Option::TYPE_TOGGLE;
	Options::Option::SHOW_IP.desc = "show-ip";

	Options::Option::ALLOW_ONLY_WIFI_IP.type = Options::Option::TYPE_TOGGLE;
	Options::Option::ALLOW_ONLY_WIFI_IP.desc = "allow-only-wifi-ip (Korea)";
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	server = new ServerManager;

	initOptions();

	soinfo2 *handle = (soinfo2 *) dlopen("libminecraftpe.so", RTLD_LAZY);

	void *handleLoginPacket = dlsym(handle, "_ZN20ServerNetworkHandler6handleERKN6RakNet10RakNetGUIDEP11LoginPacket");
	MSHookFunction(handleLoginPacket, (void *) &ServerNetworkHandler$handleLoginPacket_hook, (void **) &ServerNetworkHandler$handleLoginPacket_real);

	void *handleTextPacket = dlsym(handle, "_ZN20ServerNetworkHandler6handleERKN6RakNet10RakNetGUIDEP10TextPacket");
	MSHookFunction(handleTextPacket, (void *) &ServerNetworkHandler$handleTextPacket_hook, (void **) &ServerNetworkHandler$handleTextPacket_real);

	MSHookFunction((void *) &ServerNetworkHandler::onDisconnect, (void *) &ServerNetworkHandler$onDisconnect_hook, (void **) &ServerNetworkHandler$onDisconnect_real);

	MSHookFunction((void *) &MinecraftClient::init, (void *) &MinecraftClient$init_hook, (void **) &MinecraftClient$init_real);
	MSHookFunction((void *) &Touch::StartMenuScreen::handleBackEvent, (void *) &Touch$StartMenuScreen$handleBackEvent_hook, (void **) &Touch$StartMenuScreen$handleBackEvent_real);
	MSHookFunction((void *) &MinecraftClient::leaveGame, (void *) &MinecraftClient$leaveGame_hook, (void **) &MinecraftClient$leaveGame_real);
	MSHookFunction((void *) &LocalPlayer::tickWorld, (void *) &LocalPlayer$tickWorld_hook, (void **) &LocalPlayer$tickWorld_real);
	MSHookFunction((void *) &Minecraft::getServerName, (void *) &Minecraft$getServerName_hook, (void **) &Minecraft$getServerName_real);

	MSHookFunction((void *) &ChatScreen::sendChatMessage, (void *) &ChatScreen$sendChatMessage_hook, (void **) &ChatScreen$sendChatMessage_real);

	MSHookFunction((void *) &RakNetInstance::_startupIfNeeded, (void *) &RakNetInstance$_startupIfNeeded_hook, (void **) &RakNetInstance$_startupIfNeeded_real);
	MSHookFunction((void *) &RakNetInstance::host, (void *) &RakNetInstance$host_hook, (void **) &RakNetInstance$host_real);

	MSHookFunction((void *) &ServerPlayer::normalTick, (void *) &ServerPlayer$normalTick_hook, (void **) &ServerPlayer$normalTick_real);

	MSHookFunction((void *) &OptionsScreen::_generateOptionScreensDefault, (void *) &OptionsScreen$_generateOptionScreensDefault_hook, (void **) &OptionsScreen$_generateOptionScreensDefault_real);
	//tiny_hook((uint32_t *)(void *) &OptionsScreen::_generateOptionScreensDefault, (uint32_t) &OptionsScreen$_generateOptionScreensDefault_hook);

	MSHookFunction((void *) &Options::set, (void *) &Options$setString_hook, (void **) &Options$setString_real);
	MSHookFunction((void *) &Options::getStringValue, (void *) &Options$getStringValue_hook, (void **) &Options$getStringValue_real);
	MSHookFunction((void *) &Options::getBooleanValue, (void *) &Options$getBooleanValue_hook, (void **) &Options$getBooleanValue_real);
	MSHookFunction((void *) &Options::toggle, (void *) &Options$toggle_hook, (void **) &Options$toggle_real);
	MSHookFunction((void *) &Options::save, (void *) &Options$save_hook, (void **) &Options$save_real);
	MSHookFunction((void *) &Options::_load, (void *) &Options$_load_hook, (void **) &Options$_load_real);

	return JNI_VERSION_1_2;
}
