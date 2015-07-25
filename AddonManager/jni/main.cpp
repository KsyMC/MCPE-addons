#include <jni.h>
#include <dlfcn.h>

#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/gui/StartMenuScreen.h"
#include "minecraftpe/client/gui/PauseScreen.h"
#include "minecraftpe/client/gui/TButton.h"
#include "minecraftpe/client/gui/ImageWithBackground.h"
#include "minecraftpe/util/Color.h"
#include "minecraftpe/util/Util.h"

#include "AddonManager/client/gui/AddonManagerScreen.h"

#include "AddonManager.h"
#include "AddonManagerAddon.h"

#include "Substrate.h"
#include "dl_internal.h"
#include "shared.h"

AddonManager addonManager;
AddonManagerAddon addonManagerAddon;
std::vector<Addon *> addons;
Touch::TButton *modButton;

static void (*Touch$StartMenuScreen$Destructor_real)(Touch::StartMenuScreen *);
static void Touch$StartMenuScreen$Destructor_hook(Touch::StartMenuScreen *_this)
{
	Touch$StartMenuScreen$Destructor_real(_this);

	delete modButton;
	modButton = NULL;
}

static void (*Touch$StartMenuScreen$init_real)(Touch::StartMenuScreen *);
static void Touch$StartMenuScreen$init_hook(Touch::StartMenuScreen *_this)
{
	Touch$StartMenuScreen$init_real(_this);

	if (!modButton)
	{
		modButton = new Touch::TButton(-1, "Addons", NULL, false, 0x7FFFFFFF);
		modButton->init(_this->mc);
	}
	_this->buttonList.push_back(modButton);
}

static void (*Touch$StartMenuScreen$render_real)(Touch::StartMenuScreen *, int, int, float);
static void Touch$StartMenuScreen$render_hook(Touch::StartMenuScreen *_this, int x, int y, float f)
{
	Touch$StartMenuScreen$render_real(_this, x, y, f);
	_this->screenRenderer.drawString(_this->mc->font, "AddonManager V1.1", 0, _this->height - 40, Color::WHITE);
	_this->screenRenderer.drawString(_this->mc->font, Util::toString((int) addons.size()) + " Addons", 0, _this->height - 30, Color::WHITE);
}

static void (*Touch$StartMenuScreen$setupPositions_real)(Touch::StartMenuScreen *);
static void Touch$StartMenuScreen$setupPositions_hook(Touch::StartMenuScreen *_this)
{
	Touch$StartMenuScreen$setupPositions_real(_this);

	modButton->xPosition = _this->languageButton->xPosition;
	modButton->yPosition = _this->languageButton->yPosition - _this->languageButton->height - 2;
	modButton->width = _this->width - _this->languageButton->xPosition - 2;
	modButton->height = _this->languageButton->height;
}

static void (*Touch$StartMenuScreen$buttonClicked_real)(Touch::StartMenuScreen *, Button *);
static void Touch$StartMenuScreen$buttonClicked_hook(Touch::StartMenuScreen *_this, Button *button)
{
	if (button == modButton)
		_this->mc->setScreen(new AddonManagerScreen(false));
	else
		Touch$StartMenuScreen$buttonClicked_real(_this, button);
}

static void (*PauseScreen$Destructor_real)(PauseScreen *);
static void PauseScreen$Destructor_hook(PauseScreen *_this)
{
	PauseScreen$Destructor_real(_this);

	delete modButton;
	modButton = NULL;
}

static void (*PauseScreen$init_real)(PauseScreen *);
static void PauseScreen$init_hook(PauseScreen *_this)
{
	PauseScreen$init_real(_this);

	if (!modButton)
	{
		modButton = new Touch::TButton(-1, "Addons", NULL, false, 0x7FFFFFFF);
		modButton->init(_this->mc);
	}
	_this->buttonList.push_back(modButton);
}

static void (*PauseScreen$setupPositions_real)(PauseScreen *);
static void PauseScreen$setupPositions_hook(PauseScreen *_this)
{
	PauseScreen$setupPositions_real(_this);

	_this->optionButton->width = _this->optionButton->width / 2 - 3;

	modButton->xPosition = _this->optionButton->xPosition + _this->optionButton->width + 6;
	modButton->yPosition = _this->optionButton->yPosition;
	modButton->width = _this->optionButton->width;
	modButton->height = _this->optionButton->height;
}

static void (*PauseScreen$buttonClicked_real)(PauseScreen *, Button *);
static void PauseScreen$buttonClicked_hook(PauseScreen *_this, Button *button)
{
	if (button == modButton)
		_this->mc->setScreen(new AddonManagerScreen(true));
	else
		PauseScreen$buttonClicked_real(_this, button);
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	soinfo2 *handle = (soinfo2 *) dlopen("libminecraftpe.so", RTLD_LAZY);
	void *Touch$StartMenuScreen$Destructor = dlsym(handle, "_ZN5Touch15StartMenuScreenD2Ev");
	void *PauseScreen$Destructor = dlsym(handle, "_ZN11PauseScreenD2Ev");

	MSHookFunction(Touch$StartMenuScreen$Destructor, (void *) &Touch$StartMenuScreen$Destructor_hook, (void **) &Touch$StartMenuScreen$Destructor_real);
	MSHookFunction((void *) &Touch::StartMenuScreen::init, (void *) &Touch$StartMenuScreen$init_hook, (void **) &Touch$StartMenuScreen$init_real);
	MSHookFunction((void *) &Touch::StartMenuScreen::render, (void *) &Touch$StartMenuScreen$render_hook, (void **) &Touch$StartMenuScreen$render_real);
	MSHookFunction((void *) &Touch::StartMenuScreen::setupPositions, (void *) &Touch$StartMenuScreen$setupPositions_hook, (void **) &Touch$StartMenuScreen$setupPositions_real);
	MSHookFunction((void *) &Touch::StartMenuScreen::buttonClicked, (void *) &Touch$StartMenuScreen$buttonClicked_hook, (void **) &Touch$StartMenuScreen$buttonClicked_real);
	MSHookFunction(PauseScreen$Destructor, (void *) &PauseScreen$Destructor_hook, (void **) &PauseScreen$Destructor_real);
	MSHookFunction((void *) &PauseScreen::init, (void *) &PauseScreen$init_hook, (void **) &PauseScreen$init_real);
	MSHookFunction((void *) &PauseScreen::setupPositions, (void *) &PauseScreen$setupPositions_hook, (void **) &PauseScreen$setupPositions_real);
	MSHookFunction((void *) &PauseScreen::buttonClicked, (void *) &PauseScreen$buttonClicked_hook, (void **) &PauseScreen$buttonClicked_real);

	AddonManager::registerAddon(&addonManagerAddon);

	return JNI_VERSION_1_2;
}
