#include "SMOfflinePlayer.h"
#include "ServerManager.h"

SMOfflinePlayer::SMOfflinePlayer(ServerManager *server, std::string const &name)
{
	this->server = server;

	this->name = name;
}

bool SMOfflinePlayer::isOnline()
{
	return getPlayer() != NULL;
}

std::string SMOfflinePlayer::getName() const
{
	return name;
}

bool SMOfflinePlayer::isBanned() const
{
	return server->isBanned(name);
}

bool SMOfflinePlayer::isWhitelisted() const
{
	return server->isWhitelisted(name);
}

bool SMOfflinePlayer::isOp() const
{
	return server->isOp(name);
}

void SMOfflinePlayer::setBanned(bool banned)
{
	if(banned)
		server->addBanned(name);
	else
		server->removeBanned(name);
}

void SMOfflinePlayer::setWhitelisted(bool value)
{
	if(value)
		server->addWhitelist(name);
	else
		server->removeWhitelist(name);
}

void SMOfflinePlayer::setOp(bool value)
{
	if(isOp())
		return;

	if(value)
		server->addOp(name);
	else
		server->removeOp(name);
}

SMPlayer *SMOfflinePlayer::getPlayer()
{
	return server->getPlayerExact(name);
}
