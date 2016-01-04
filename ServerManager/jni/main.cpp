#include <jni.h>

#include "servermanager/Server.h"
#include "servermanager/client/CustomMinecraftClient.h"
#include "servermanager/client/gui/CustomChatScreen.h"
#include "servermanager/entity/CustomLocalPlayer.h"
#include "servermanager/network/CustomServerNetworkHandler.h"
#include "servermanager/network/CustomRakNetInstance.h"

Server *server = new Server;

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	CustomMinecraftClient::setupHooks();
	CustomLocalPlayer::setupHooks();
	CustomChatScreen::setupHooks();
	CustomRakNetInstance::setupHooks();
	CustomServerNetworkHandler::setupHooks();

	return JNI_VERSION_1_2;
}
