#pragma once

#include "servermanager/entity/SMPlayer.h"

class LocalPlayer;

class SMLocalPlayer : public SMPlayer
{
public:
	SMLocalPlayer(LocalPlayer *entity);

	void sendMessage(const std::string &message);
	void sendTranslation(const std::string &message, const std::vector<std::string> &params);
	void sendPopup(const std::string &message, const std::string &subtitle = "");
	void sendTip(const std::string &message);

	bool isLocalPlayer() const;

	LocalPlayer *getHandle() const;
};
