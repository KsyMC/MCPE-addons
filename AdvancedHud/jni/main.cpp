#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <fstream>

#include "Substrate.h"
#include "dl_internal.h"

#define LOG_TAG 	"AdvancedHud"
#define LOGE(...) 	__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...) 	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/settings/Options.h"
//#include "minecraftpe/client/gui/Gui.h"
#include "minecraftpe/client/gui/OptionsScreen.h"
#include "minecraftpe/client/gui/OptionsPane.h"
#include "minecraftpe/client/gui/OptionsGroup.h"
#include "minecraftpe/util/Util.h"

Options::Option Options::Option::GUI_SCALE = {3, "options.buttonSize"};

std::string file;
int guiScale = 0;

static void setGuiScale(MinecraftClient *mc, int scale)
{
	mc->setSize(mc->getWidth(), mc->getHeight(), (float)scale);
}

/*static void ( *Gui$renderToolBar_real )( Gui *, float, float );
static void Gui$renderToolBar_hook( Gui *_this, float fDeltaTime, float f )
{
	float fInvGuiScale = Gui::InvGuiScale;
	_this->m_pMC->m_iHeight * fInvGuiScale;

	_this->m_pMC->m_pTextures->bindTexture( "gui/gui.png", 0, true );

	int iX, iY;
	_this->getNumSlots( 0, iX, iY );
	iY += 4;

	_this->m_pMC->getLocalPlayer()->m_pInventory;
	Gui$renderToolBar_real( _this, fDeltaTime, f );
}*/

static void (*MinecraftClient$setSize_real)(MinecraftClient *, int, int, float);
static void MinecraftClient$setSize_hook(MinecraftClient *_this, int width, int height, float scale)
{
	MinecraftClient$setSize_real(_this, width, height, (float)guiScale);
}

static void (*MinecraftClient$initOptionObservers_real)(MinecraftClient *);
static void MinecraftClient$initOptionObservers_hook(MinecraftClient *_this)
{
	MinecraftClient$initOptionObservers_real(_this);

	Options *options = _this->getOptions();
	options->registerIntObserver(_this, Options::Option::GUI_SCALE, std::bind(setGuiScale, _this, std::placeholders::_1));
}

static void (*OptionsScreen$_generateOptionScreens_real)(OptionsScreen *);
static void OptionsScreen$_generateOptionScreens_hook(OptionsScreen *_this)
{
	OptionsScreen$_generateOptionScreens_real(_this);

	OptionsGroup *group = _this->vectorPanes[2]->createOptionsGroup("Advanced Hud V1.4 by KsyMC", true);
	group->createStepSlider(Options::Option::GUI_SCALE, *_this->client);
}

static std::vector<int> (*Options$getValues_real)(Options *, const Options::Option *);
static std::vector<int> Options$getValues_hook(Options *_this, const Options::Option *option)
{
	if(option == &Options::Option::GUI_SCALE) return {0, 1, 2, 3, 4, 5, 6};
	else return Options$getValues_real(_this, option);
}

static int (*Options$getIntValue_real)(Options *, const Options::Option *);
static int Options$getIntValue_hook(Options *_this, const Options::Option *option)
{
	if(option == &Options::Option::GUI_SCALE) return guiScale;
	else return Options$getIntValue_real(_this, option);
}

static void (*Options$setI_real)(Options *, const Options::Option *, int);
static void Options$setI_hook(Options *_this, const Options::Option *option, int value)
{
	if(option == &Options::Option::GUI_SCALE) guiScale = value;
	else Options$setI_real(_this, option, value);
}

static void (*Options$save_real)(Options *);
static void Options$save_hook(Options *_this)
{
	Options$save_real(_this);

	std::ofstream ofs(file.c_str());
	ofs << "guiscale:" << guiScale << std::endl;
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

		if(s.empty())
			continue;

		if(!s[0].compare("guiscale"))
			Options::_readInt(s[1], guiScale);
	}
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	soinfo2 *handle = (soinfo2 *) dlopen("libminecraftpe.so", RTLD_LAZY);

	void *initOptionObservers = dlsym(handle, "_ZN15MinecraftClient19initOptionObserversEv");
	void *generateOptionScreens = dlsym(handle, "_ZN13OptionsScreen21generateOptionScreensEv");
	void *setIntOption = dlsym(handle, "_ZN7Options3setEPKNS_6OptionEi");

	//MSHookFunction((void *) &Gui::renderToolBar, (void *) &Gui$renderToolBar_hook, (void **) &Gui$renderToolBar_real);
	MSHookFunction((void *) &MinecraftClient::setSize, (void *) &MinecraftClient$setSize_hook, (void **) &MinecraftClient$setSize_real);
	MSHookFunction(initOptionObservers, (void *) &MinecraftClient$initOptionObservers_hook, (void **) &MinecraftClient$initOptionObservers_real);
	MSHookFunction(generateOptionScreens, (void *) &OptionsScreen$_generateOptionScreens_hook, (void **) &OptionsScreen$_generateOptionScreens_real);
	MSHookFunction((void *) &Options::getValues, (void *) &Options$getValues_hook, (void **) &Options$getValues_real);
	MSHookFunction((void *) &Options::getIntValue, (void *) &Options$getIntValue_hook, (void **) &Options$getIntValue_real);
	MSHookFunction(setIntOption, (void *) &Options$setI_hook, (void **) &Options$setI_real);
	MSHookFunction((void *) &Options::save, (void *) &Options$save_hook, (void **) &Options$save_real);
	MSHookFunction((void *) &Options::_load, (void *) &Options$_load_hook, (void **) &Options$_load_real);

	return JNI_VERSION_1_2;
}
