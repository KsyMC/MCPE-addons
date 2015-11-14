#include <jni.h>
#include <dlfcn.h>

#include "minecraftpe/client/Minecraft.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/command/ClientCommands.h"
#include "minecraftpe/command/ServerCommands.h"

#include "Substrate.h"
#include "dl_internal.h"
#include "shared.h"

static void (*MinecraftClient$setupCommandParser_real)(MinecraftClient *);
static void MinecraftClient$setupCommandParser_hook(MinecraftClient *_this)
{
	Minecraft *minecraft = _this->getServer();
	ServerCommands::setupStandardServer(*minecraft->getCommandParser(), *minecraft->getLevel());
	MinecraftClient$setupCommandParser_real(_this);
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	soinfo2 *handle = (soinfo2 *) dlopen("libminecraftpe.so", RTLD_LAZY);
	MSHookFunction((void *) &MinecraftClient::setupCommandParser, (void *) &MinecraftClient$setupCommandParser_hook, (void **) &MinecraftClient$setupCommandParser_real);

	return JNI_VERSION_1_2;
}
