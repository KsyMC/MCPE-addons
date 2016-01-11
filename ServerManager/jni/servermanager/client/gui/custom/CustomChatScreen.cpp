#include "servermanager/client/gui/custom/CustomChatScreen.h"
#include "servermanager/ServerManager.h"
#include "servermanager/entity/SMLocalPlayer.h"
#include "servermanager/event/player/PlayerChatEvent.h"
#include "servermanager/event/player/PlayerCommandPreprocessEvent.h"
#include "servermanager/plugin/PluginManager.h"
#include "servermanager/util/SMUtil.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/Minecraft.h"
#include "minecraftpe/client/AppPlatform.h"
#include "minecraftpe/client/gui/ChatScreen.h"
#include "minecraftpe/level/Level.h"
#include "hook/Substrate.h"

FUNCTION_HOOK_CPP(void, CustomChatScreen, sendChatMessage, ChatScreen *real)
{
	if(!real->mc->getServer()->getLevel()->isClientSide())
	{
		if(real->message.empty())
			return;

		if(real->message[0] == '#')
		{
			PlayerCommandPreprocessEvent event(ServerManager::getLocalPlayer(), real->message);
			ServerManager::getPluginManager()->callEvent(event);

			if(event.isCancelled())
				return;

			std::string message = event.getMessage();
			ServerManager::dispatchCommand(event.getPlayer(), message.erase(0, 1));
		}
		else
		{
			PlayerChatEvent event(ServerManager::getLocalPlayer(), real->message);
			ServerManager::getPluginManager()->callEvent(event);

			if(event.isCancelled())
				return;

			std::string message = SMUtil::format(event.getFormat().c_str(), event.getPlayer()->getDisplayName().c_str(), event.getMessage().c_str());
			ServerManager::broadcastMessage(message);
		}
		real->message.clear();

		if(AppPlatform::mSingleton->isKeyboardVisible())
			AppPlatform::mSingleton->updateTextBoxText("");
	}
	else
		sendChatMessage_real(real);
}

void CustomChatScreen::setupHooks()
{
	MSHookFunction((void *) &ChatScreen::sendChatMessage, (void *) &sendChatMessage, (void **) &sendChatMessage_real);
}
