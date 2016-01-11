#include <jni.h>

#include "servermanager/Server.h"
#include "servermanager/client/custom/CustomMinecraftClient.h"
#include "servermanager/client/gui/custom/CustomChatScreen.h"
#include "servermanager/entity/custom/CustomLocalPlayer.h"
#include "servermanager/entity/custom/CustomPlayer.h"
#include "servermanager/entity/custom/CustomItemEntity.h"
#include "servermanager/entity/custom/CustomCreeper.h"
#include "servermanager/entity/custom/CustomArrow.h"
#include "servermanager/level/custom/CustomLevel.h"
#include "servermanager/network/custom/CustomServerNetworkHandler.h"
#include "servermanager/network/custom/CustomRakNetInstance.h"

const Server *server = new Server;

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	CustomMinecraftClient::setupHooks();
	CustomChatScreen::setupHooks();
	CustomLocalPlayer::setupHooks();
	CustomPlayer::setupHooks();
	CustomItemEntity::setupHooks();
	CustomCreeper::setupHooks();
	CustomArrow::setupHooks();
	CustomLevel::setupHooks();
	CustomRakNetInstance::setupHooks();
	CustomServerNetworkHandler::setupHooks();

	return JNI_VERSION_1_2;
}
