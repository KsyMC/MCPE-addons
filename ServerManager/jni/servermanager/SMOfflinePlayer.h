#pragma once

#include "ISMPlayer.h"

class ServerManager;

class SMOfflinePlayer : public ISMPlayer
{
private:
	ServerManager *server;

	std::string name;

public:
	SMOfflinePlayer(ServerManager *server, std::string const &name);

	virtual bool isOnline();

	virtual std::string getName() const;

	virtual bool isBanned() const;
	virtual bool isWhitelisted() const;
	virtual bool isOp() const;

	virtual void setBanned(bool banned);
	virtual void setWhitelisted(bool value);
	virtual void setOp(bool value);

	virtual SMPlayer *getPlayer();
};
