#include "AddonManagerScreen.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/gui/THeader.h"
#include "minecraftpe/client/gui/HeaderButton.h"
#include "minecraftpe/client/gui/PackedScrollContainer.h"
#include "minecraftpe/client/gui/Label.h"
#include "minecraftpe/client/gui/TButton.h"
#include "minecraftpe/client/gui/StartMenuScreen.h"
#include "minecraftpe/client/gui/PauseScreen.h"
#include "minecraftpe/client/gui/IntRectangle.h"

#include "AddonListItemElement.h"
#include "Addon.h"

#include "shared.h"

AddonManagerScreen::AddonManagerScreen(bool inGame)
{
	this->inGame = inGame;
	managerHeader = NULL;
	backButton = NULL;
	addonContainer = NULL;
	addonNameLabel = NULL;
	addonDescLabel = NULL;
	optionsButton = NULL;
	optionsScreen = NULL;
}

AddonManagerScreen::~AddonManagerScreen()
{
	delete managerHeader;
	delete backButton;
	delete addonContainer;
	delete addonNameLabel;
	delete addonDescLabel;
	delete optionsButton;
}

void AddonManagerScreen::render(int x, int y, float f)
{
	if (inGame)
		Screen::renderBackground(0);
	else
		Screen::renderMenuBackground(f);

	Screen::render(x, y, f);
}

void AddonManagerScreen::init()
{
	managerHeader = new Touch::THeader(0, "AddonManager By KsyMC");
	backButton = new Touch::HeaderButton(0, *mc, "gui.back", false, false);
	addonContainer = new PackedScrollContainer(true, false);
	addonNameLabel = new Label(*mc, "", Color::YELLOW, 0, 0, 0, true);
	addonDescLabel = new Label(*mc, "", Color::WHITE, 0, 0, 0, true);
	optionsButton = new Touch::TButton(1, "Options ...", NULL, false, 0x7FFFFFFF);

	addonContainer->setBackground(mc, "gui/spritesheet.png", {0, 44, 8, 8}, 2, 3);
	optionsButton->init(mc);

	for (auto addon : addons)
	{
		std::shared_ptr<AddonListItemElement> item(new AddonListItemElement(mc, addon, std::bind(&AddonManagerScreen::setItem, this, std::placeholders::_1)));
		addonContainer->addChild(item);
	}

	buttonList.push_back(managerHeader);
	buttonList.push_back(backButton);
	elementList2.push_back(addonContainer);
	elementList2.push_back(addonNameLabel);
	elementList2.push_back(addonDescLabel);
	buttonList.push_back(optionsButton);

	setItem(addons[0]);
}

void AddonManagerScreen::setupPositions()
{
	managerHeader->width = width;

	addonContainer->xPosition = 10;
	addonContainer->yPosition = managerHeader->height + 10;
	addonContainer->width = width / 2 - 15;
	addonContainer->height = height - managerHeader->height - 20;

	addonNameLabel->xPosition = width / 2 + 5;
	addonNameLabel->yPosition = managerHeader->height + 10;

	addonDescLabel->xPosition = addonNameLabel->xPosition;
	addonDescLabel->yPosition = addonNameLabel->yPosition + 20;
	addonDescLabel->setWidth(width - addonDescLabel->xPosition - 5);

	optionsButton->xPosition = addonNameLabel->xPosition;
	optionsButton->yPosition = height - optionsButton->height - 10;
	optionsButton->width = width / 2 - 15;
}

bool AddonManagerScreen::handleBackEvent(bool b)
{
	if (!b)
		closeScreen();
	return true;
}

void AddonManagerScreen::buttonClicked(Button *button)
{
	switch (button->id)
	{
	case 0: // Back
		closeScreen();
		break;
	case 1: // Options ...
		mc->setScreen(optionsScreen);
		break;
	}
}

void AddonManagerScreen::setItem(Addon *addon)
{
	addonNameLabel->setTextRaw(addon->getName());
	addonDescLabel->setTextRaw(addon->getDescription());
	optionsScreen = addon->getOptionsScreen(new AddonManagerScreen(inGame));
	optionsButton->setActiveAndVisibility(optionsScreen != NULL);
}

void AddonManagerScreen::closeScreen()
{
	if (inGame)
		mc->setScreen(new PauseScreen(true));
	else
		mc->setScreen(new Touch::StartMenuScreen());
}
