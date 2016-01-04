#include "servermanager/Server.h"
#include "servermanager/ServerManager.h"
#include "servermanager/client/settings/SMOptions.h"
#include "servermanager/client/resources/SMList.h"
#include "servermanager/client/resources/BanList.h"
#include "servermanager/client/resources/BanEntry.h"
#include "servermanager/command/CommandMap.h"
#include "servermanager/command/Command.h"
#include "servermanager/level/SMLevel.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/entity/SMLocalPlayer.h"
#include "servermanager/plugin/PluginManager.h"
#include "servermanager/plugin/Plugin.h"
#include "servermanager/plugin/PluginDescriptionFile.h"
#include "servermanager/util/SMUtil.h"
#include "minecraftpe/client/Minecraft.h"
#include "minecraftpe/network/PacketSender.h"
#include "minecraftpe/network/protocol/TextPacket.h"
#include "minecraftpe/network/ServerNetworkHandler.h"
#include "minecraftpe/util/File.h"

Server::Server()
{
	ServerManager::setServer(this);

	started = false;
	level = NULL;
	server = NULL;

	options = new SMOptions("servermanager.txt");
	banByName = new BanList("banned-players.txt");
	banByIP = new BanList("banned-ips.txt");
	operators = new SMList("ops.txt");
	whitelist = new SMList("white-list.txt");

	commandMap = new CommandMap;
	pluginManager = new PluginManager(this, commandMap);

	localPlayer = NULL;
}

Server::~Server()
{
	pluginManager->clearPlugins();

	delete options;
	delete banByName;
	delete banByIP;
	delete operators;
	delete whitelist;
	delete commandMap;
}

void Server::init(Minecraft *server, const std::string &path)
{
	this->server = server;

	serverDir = path + "servermanager/";
	pluginDir = serverDir + "plugins/";

	load(serverDir);

	loadPlugins();
	enablePlugins(PluginLoadOrder::STARTUP);
}

void Server::load(const std::string &path)
{
	File::createFolder(path);

	options->load(path);
	banByName->load(path);
	banByIP->load(path);
	operators->load(path);
	whitelist->load(path);
}

void Server::start(LocalPlayer *localPlayer, Level *level)
{
	if(started)
		return;

	this->level = new SMLevel(level);
	this->localPlayer = new SMLocalPlayer(localPlayer);

	this->level->addPlayer(this->localPlayer);

	started = true;

	enablePlugins(PluginLoadOrder::POSTWORLD);
}

void Server::stop()
{
	if(!started)
		return;

	started = false;

	disablePlugins();

	delete level;
	level = NULL;

	options->save();
	banByName->save();
	banByIP->save();
	operators->save();
	whitelist->save();
}

SMOptions *Server::getOptions() const
{
	return options;
}

void Server::saveOptions()
{
	options->save();
}

void Server::registerPlugin(Plugin *plugin)
{
	pluginManager->registerPlugin(plugin);
}

void Server::loadPlugins()
{
	if(File::exists(pluginDir))
	{
		for(Plugin *plugin : pluginManager->loadPlugins(pluginDir))
			plugin->onLoad();
	}
	else
		File::createFolder(pluginDir);
}

void Server::enablePlugins(PluginLoadOrder type)
{
	if(type == PluginLoadOrder::STARTUP)
	{

	}

	for(Plugin *plugin : pluginManager->getPlugins())
		if(!plugin->isEnabled() && plugin->getDescription()->getLoad() == type)
			loadPlugin(plugin);

	if(type == PluginLoadOrder::POSTWORLD)
	{
		commandMap->setFallbackCommands();
		setVanillaCommands();
	}
}

void Server::disablePlugins()
{
	pluginManager->disablePlugins();
}

void Server::setVanillaCommands()
{

}

void Server::loadPlugin(Plugin *plugin)
{
	pluginManager->enablePlugin(plugin);
}

SMLocalPlayer *Server::getLocalPlayer() const
{
	return localPlayer;
}

void Server::kickPlayer(SMPlayer *player, const std::string &reason)
{
	if(!player || player->isLocalPlayer())
		return;

	ServerNetworkHandler *handler = (ServerNetworkHandler *)getServer()->getNetEventCallback();
	handler->disconnectClient(player->getHandle()->guid, reason);
}

void Server::broadcastMessage(const std::string &message)
{
	for(std::string m : SMUtil::split(message, '\n'))
	{
		if(m.empty())
			continue;

		TextPacket pk;
		pk.type = TextPacket::TYPE_RAW;
		pk.message = m;
		getServer()->getPacketSender()->send(pk);
	}
}

void Server::broadcastTranslation(const std::string &message, const std::vector<std::string> &params)
{
	TextPacket pk;
	pk.type = TextPacket::TYPE_TRANSLATION;
	pk.message = message;
	pk.params = params;
	getServer()->getPacketSender()->send(pk);
}

void Server::broadcastTip(const std::string &message)
{
	TextPacket pk;
	pk.type = TextPacket::TYPE_TIP;
	pk.message = message;
	getServer()->getPacketSender()->send(pk);
}

void Server::broadcastPopup(const std::string &message, const std::string &subtitle)
{
	TextPacket pk;
	pk.type = TextPacket::TYPE_POPUP;
	pk.source = message;
	pk.message = subtitle;
	getServer()->getPacketSender()->send(pk);
}

int Server::getMaxPlayers() const
{
	return options->getServerPlayers();
}

int Server::getPort() const
{
	return options->getServerPort();
}

int Server::getViewDistance() const
{
	return options->getViewDistance();
}

std::string Server::getServerName() const
{
	return options->getServerName();
}

bool Server::hasWhitelist() const
{
	return options->hasWhitelist();
}

bool Server::getPvP() const
{
	return options->getPvP();
}

void Server::setWhitelist(bool value)
{
	options->setWhitelist(value);
}

void Server::setPvP(bool value)
{
	options->setPvP(value);
}

bool Server::dispatchCommand(SMPlayer *player, const std::string &commandLine)
{
	if(!player->isLocalPlayer() && !isOp(player->getName()))
	{
		player->sendTranslation("§c%commands.generic.permission", {});
		return false;
	}

	if(commandMap->dispatch(player, commandLine))
		return true;

	player->sendTranslation("§c%commands.generic.notFound", {});
	return false;
}

PluginCommand *Server::getPluginCommand(const std::string &name)
{
	Command *command = commandMap->getCommand(name);
	if(command->isPluginCommand())
		return (PluginCommand *)command;
	return NULL;
}

SMLevel *Server::getLevel() const
{
	return level;
}

BanList *Server::getBanList(int type) const
{
	if(type == BanList::NAME)
		return banByName;
	else if(type == BanList::IP)
		return banByIP;

	return NULL;
}

SMList *Server::getWhitelistList() const
{
	return whitelist;
}

SMList *Server::getOPList() const
{
	return operators;
}

void Server::banIP(const std::string &address)
{
	BanEntry *entry = new BanEntry(address);

	banByIP->add(entry);
	banByIP->save();
}

void Server::unbanIP(const std::string &address)
{
	banByIP->pardon(address);
	banByIP->save();
}

void Server::addWhitelist(const std::string &name)
{
	whitelist->add(name);
	whitelist->save();
}

void Server::removeWhitelist(const std::string &name)
{
	whitelist->remove(name);
	whitelist->save();
}

void Server::reloadWhitelist()
{
	whitelist->reload();
}

void Server::addOp(const std::string &name)
{
	operators->add(SMUtil::toLower(name));
	operators->save();
}

void Server::removeOp(const std::string &name)
{
	operators->remove(SMUtil::toLower(name));
	operators->save();
}

bool Server::isWhitelisted(const std::string &name) const
{
	return !options->hasWhitelist() || operators->isExist(SMUtil::toLower(name)) || whitelist->isExist(SMUtil::toLower(name));
}

bool Server::isOp(const std::string &name) const
{
	return operators->isExist(SMUtil::toLower(name));
}

CommandMap *Server::getCommandMap() const
{
	return commandMap;
}

PluginManager *Server::getPluginManager() const
{
	return pluginManager;
}

std::string Server::getGamemodeString(GameType type)
{
	switch(type)
	{
	case GAMETYPE_SURVIVAL:
		return "%gameMode.survival";
	case GAMETYPE_CREATIVE:
		return "%gameMode.creative";
	case GAMETYPE_ADVENTURE:
		return "%gameMode.adventure";
	case GAMETYPE_SPECTATOR:
		return "%gameMode.spectator";
	}
	return "UNKNOWN";
}

GameType Server::getGamemodeFromString(const std::string &value)
{
	std::string newStr = SMUtil::toLower(SMUtil::trim(value.c_str()));

	if(!newStr.compare("0") || !newStr.compare("survival") || !newStr.compare("s"))
		return GameType::GAMETYPE_SURVIVAL;
	else if(!newStr.compare("1") || !newStr.compare("creative") || !newStr.compare("c"))
		return GameType::GAMETYPE_CREATIVE;
	else if(!newStr.compare("2") || !newStr.compare("adventure") || !newStr.compare("a"))
		return GameType::GAMETYPE_ADVENTURE;
	else if(!newStr.compare("3") || !newStr.compare("spectator") || !newStr.compare("view") || !newStr.compare("v"))
		return GameType::GAMETYPE_SPECTATOR;

	return (GameType)-1;
}

Minecraft *Server::getServer() const
{
	return server;
}
