#pragma once

#include "SMPlayer.h"

class SMLocalPlayer : public SMPlayer
{
public:
	SMLocalPlayer(ServerManager *server, Player *player, RakNet::RakNetGUID const &guid);

	virtual void sendMessage(TextContainer const &message);
	virtual void sendTranslation(std::string const &message, std::vector<std::string> const &parameters);
	virtual void sendPopup(std::string const &message, std::string const &subtitle = "");
	virtual void sendTip(std::string const &message);

	virtual bool isLocalPlayer() const;
};
