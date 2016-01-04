#include "servermanager/entity/SMLocalPlayer.h"
#include "servermanager/util/SMUtil.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/gui/Gui.h"
#include "minecraftpe/entity/player/LocalPlayer.h"

SMLocalPlayer::SMLocalPlayer(LocalPlayer *entity)
	: SMPlayer(entity, "127.0.0.1")
{
	displayName = entity->username;
	listName = entity->username;
}

void SMLocalPlayer::sendMessage(const std::string &message)
{
	Gui *gui = getHandle()->client->getGui();
	for(std::string m : SMUtil::split(message, '\n'))
	{
		if(m.empty())
			continue;

		gui->displayClientMessage(m);
	}
}

void SMLocalPlayer::sendTranslation(const std::string &message, const std::vector<std::string> &params)
{
	getHandle()->client->getGui()->displayLocalizableMessage(message, params);
}

void SMLocalPlayer::sendPopup(const std::string &message, const std::string &subtitle)
{
	getHandle()->client->getGui()->showPopupNotice(message, subtitle);
}

void SMLocalPlayer::sendTip(const std::string &message)
{
	getHandle()->client->getGui()->showTipMessage(message);
}

bool SMLocalPlayer::isLocalPlayer() const
{
	return true;
}

LocalPlayer *SMLocalPlayer::getHandle() const
{
	return (LocalPlayer *)entity;
}
