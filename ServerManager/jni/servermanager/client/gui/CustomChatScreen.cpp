#include "servermanager/client/gui/CustomChatScreen.h"
#include "servermanager/ServerManager.h"
#include "servermanager/entity/SMLocalPlayer.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/Minecraft.h"
#include "minecraftpe/client/AppPlatform.h"
#include "minecraftpe/client/gui/ChatScreen.h"
#include "minecraftpe/level/Level.h"
#include "hook/Substrate.h"

FUNCTION_HOOK_CPP(void, CustomChatScreen, sendChatMessage, ChatScreen *real)
{
	if(real->mc->getServer()->getLevel()->isClientSide())
	{
		sendChatMessage_real(real);
		return;
	}

	if(real->message[0] != ' ' && real->message[1] != '/')
		sendChatMessage_real(real);
	else
	{
		ServerManager::dispatchCommand(ServerManager::getServer()->getLocalPlayer(), real->message.erase(0, 2));

		real->message = "";

		if(AppPlatform::mSingleton->isKeyboardVisible())
			AppPlatform::mSingleton->updateTextBoxText("");
	}
}

void CustomChatScreen::setupHooks()
{
	MSHookFunction((void *) &ChatScreen::sendChatMessage, (void **) &sendChatMessage, (void **) &sendChatMessage_real);
}
