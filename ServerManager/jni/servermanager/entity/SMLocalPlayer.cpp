#include "servermanager/entity/SMLocalPlayer.h"
#include "servermanager/util/SMUtil.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/gui/Gui.h"
#include "minecraftpe/entity/player/LocalPlayer.h"

SMLocalPlayer::SMLocalPlayer(Server *server, LocalPlayer *entity)
	: SMPlayer(server, entity)
{
	setAddress("127.0.0.1");
}

void SMLocalPlayer::sendRawMessage(const std::string &message)
{
	Gui *gui = getHandle()->client->getGui();

	for(std::string m : SMUtil::split(message, '\n'))
		if(!m.empty())
			gui->displayClientMessage(m);
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
