#include "servermanager/ServerManager.h"

Server *ServerManager::server;

Server *ServerManager::getServer()
{
	return server;
}

void ServerManager::setServer(Server *server)
{
	if(!ServerManager::server)
		ServerManager::server = server;
}

int ServerManager::getMaxPlayers()
{
	return server->getMaxPlayers();
}

int ServerManager::getPort()
{
	return server->getPort();
}

int ServerManager::getViewDistance()
{
	return server->getViewDistance();
}

std::string ServerManager::getServerName()
{
	return server->getServerName();
}

void ServerManager::broadcastMessage(const std::string &message)
{
	server->broadcastMessage(message);
}

void ServerManager::broadcastTranslation(const std::string &message, const std::vector<std::string> &params)
{
	server->broadcastTranslation(message, params);
}

void ServerManager::broadcastTip(const std::string &message)
{
	server->broadcastTip(message);
}

void ServerManager::broadcastPopup(const std::string &message, const std::string &subtitle)
{
	server->broadcastPopup(message, subtitle);
}

bool ServerManager::hasWhitelist()
{
	return server->hasWhitelist();
}

bool ServerManager::isWhitelisted(const std::string &name)
{
	return server->isWhitelisted(name);
}

bool ServerManager::dispatchCommand(SMPlayer *sender, const std::string &commandLine)
{
	return server->dispatchCommand(sender, commandLine);
}

PluginCommand *ServerManager::getPluginCommand(const std::string &name)
{
	return server->getPluginCommand(name);
}

void ServerManager::banIP(const std::string &address)
{
	server->banIP(address);
}

void ServerManager::unbanIP(const std::string &address)
{
	server->unbanIP(address);
}

BanList *ServerManager::getBanList(BanList::Type type)
{
	return server->getBanList(type);
}

void ServerManager::setWhitelist(bool value)
{
	server->setWhitelist(value);
}

SMList *ServerManager::getWhitelist()
{
	return server->getWhitelistList();
}

void ServerManager::reloadWhitelist()
{
	server->reloadWhitelist();
}

SMLevel *ServerManager::getLevel()
{
	return server->getLevel();
}

PluginManager *ServerManager::getPluginManager()
{
	return server->getPluginManager();
}

SMLocalPlayer *ServerManager::getLocalPlayer()
{
	return server->getLocalPlayer();
}

void ServerManager::kickPlayer(SMPlayer *player, const std::string &reason)
{
	server->kickPlayer(player, reason);
}

void ServerManager::registerPlugin(Plugin *plugin)
{
	server->registerPlugin(plugin);
}
