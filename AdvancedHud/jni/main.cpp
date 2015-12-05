#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <fstream>

#include "Substrate.h"
#include "dl_internal.h"
#include "shared.h"

#include "minecraftpe/Options.h"
#include "minecraftpe/MinecraftClient.h"
#include "minecraftpe/Util.h"

std::string file;
int guiScale = 0;

static void (*MinecraftClient$setSize_real)(MinecraftClient *, int, int, float);
static void MinecraftClient$setSize_hook(MinecraftClient *_this, int width, int height, float scale)
{
	MinecraftClient$setSize_real(_this, width, height, (float)guiScale);
}

static void (*Options$_load_real)(Options *);
static void Options$_load_hook(Options *_this)
{
	Options$_load_real(_this);

	file = _this->filepath;
	std::string findString = "options.txt";
	file.replace(file.find(findString), findString.length(), "advancedhud.txt");

	std::ifstream ifs(file.c_str());
	if(!ifs.is_open())
		return;

	std::string line;
	while(!ifs.eof())
	{
		std::getline(ifs, line);
		if(line.empty())
			continue;

		std::vector<std::string> s = Util::split(line, ':');

		if(s.empty() || s.size() != 2 || s[0].empty() || s[1].empty())
			continue;

		if(!s[0].compare("guiscale"))
			Options::_readInt(s[1], guiScale);
	}
	ifs.close();
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	soinfo2 *handle = (soinfo2 *) dlopen("libminecraftpe.so", RTLD_LAZY);

	MSHookFunction((void *) &MinecraftClient::setSize, (void *) &MinecraftClient$setSize_hook, (void **) &MinecraftClient$setSize_real);
	MSHookFunction((void *) &Options::_load, (void *) &Options$_load_hook, (void **) &Options$_load_real);

	return JNI_VERSION_1_2;
}
