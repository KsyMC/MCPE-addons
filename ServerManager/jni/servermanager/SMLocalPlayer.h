#pragma once

#include "SMPlayer.h"

class SMLocalPlayer : public SMPlayer
{
public:
	SMLocalPlayer(ServerManager *server, Player *player, RakNet::RakNetGUID const &guid);

	virtual bool dataPacket(Packet const &packet);

	virtual void sendMessage(TextContainer const &message);
	virtual void sendTranslation(std::string const &message, std::vector<std::string> const &parameters);
	virtual void sendPopup(std::string const &message, std::string const &subtitle = "");
	virtual void sendTip(std::string const &message);

	virtual void kick(std::string const &reason, bool isAdmin = true);
	virtual void close(TextContainer const &message, std::string const &reason = "generic reason", bool notify = true);

	virtual bool isLocalPlayer() const;
};
