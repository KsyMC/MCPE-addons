#include "TestScreen.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/gui/THeader.h"
#include "minecraftpe/client/gui/HeaderButton.h"
#include "minecraftpe/client/gui/NinePatchLayer.h"
#include "minecraftpe/client/gui/BlankButton.h"
#include "minecraftpe/client/gui/Label.h"
#include "minecraftpe/client/gui/ImageButton.h"
#include "minecraftpe/client/gui/TButton.h"
#include "minecraftpe/client/gui/PackedScrollContainer.h"
#include "minecraftpe/client/gui/StartMenuScreen.h"
#include "minecraftpe/client/renderer/Tessellator.h"
#include "minecraftpe/client/renderer/texture/NinePatchFactory.h"
#include "minecraftpe/util/Color.h"

#include "TestAddon/client/gui/TestListItemElement.h"

TestScreen::TestScreen()
{
	testHeader = NULL;
	backButton = NULL;
	backgroundLayer = NULL;
	blankButton = NULL;
	stringLabel = NULL;
	imageButton = NULL;
	stateLabel = NULL;
	testButton = NULL;
	toggleButton = NULL;
	container = NULL;
}

TestScreen::~TestScreen()
{
	delete testHeader;
	delete backButton;
	delete backgroundLayer;
	delete blankButton;
	delete stringLabel;
	delete imageButton;
	delete stateLabel;
	delete testButton;
	delete toggleButton;
	delete container;
}

void TestScreen::render(int i, int i1, float f)
{
	Screen::renderMenuBackground(f);
	backgroundLayer->draw(Tessellator::instance, backgroundLayer->xPosition, backgroundLayer->yPosition);

	Screen::render(i, i1, f);
}

void TestScreen::init()
{
	testHeader = new Touch::THeader(0, "THeader");
	backButton = new Touch::HeaderButton(0, *mc, "gui.back", false, false);
	blankButton = new BlankButton(1);
	stringLabel = new Label(*mc, "Label", Color::WHITE, 0, 0, 0, true);
	imageButton = new ImageButton(2, "ImageButton");
	stateLabel = new Label(*mc, "누름 : 없음", Color::WHITE, 0, 0, 0, true);
	testButton = new Touch::TButton(3, "TButton", NULL, false, 0x7FFFFFFF);
	toggleButton = new Touch::TButton(4, "Toggle", NULL, true, 0x7FFFFFFF);
	container = new PackedScrollContainer(false, false);

	imageButton->setImageDef({"gui/spritesheet.png", 0, 0, 50.0f, 50.0f, {60, 0, 18, 18}, true}, true);
	testButton->init(mc);
	toggleButton->init(mc);
	container->setBackground(mc, "gui/gui.png", {144, 184, 22, 22}, 3, 3);

	for (int i = 0; i < 10; i++)
	{
		std::shared_ptr<TestListItemElement> item(new TestListItemElement(mc));
		container->addChild(item);
	}

	buttonList.push_back(testHeader);
	buttonList.push_back(backButton);
	buttonList.push_back(blankButton);
	elementList2.push_back(stringLabel);
	buttonList.push_back(imageButton);
	elementList2.push_back(stateLabel);
	buttonList.push_back(testButton);
	buttonList.push_back(toggleButton);
	elementList2.push_back(container);

	NinePatchFactory factory(mc->textures, "gui/spritesheet.png");
	backgroundLayer = factory.createSymmetrical({34, 43, 14, 14}, 3, 3, 32.0f, 32.0f);
}

void TestScreen::setupPositions()
{
	backgroundLayer->xPosition = 5;
	backgroundLayer->yPosition = testHeader->height + 5;
	backgroundLayer->setSize(width - 10, height - testHeader->height - 10);

	testHeader->width = width;

	blankButton->xPosition = 10;
	blankButton->yPosition = testHeader->height + 10;

	stringLabel->xPosition = 10;
	stringLabel->yPosition = blankButton->yPosition + blankButton->height + 2;

	imageButton->xPosition = 10;
	imageButton->yPosition = stringLabel->yPosition + stringLabel->height + 2;

	stateLabel->xPosition = width / 2;
	stateLabel->yPosition = testHeader->height + 10;

	testButton->xPosition = width / 2;
	testButton->yPosition = stateLabel->yPosition + stateLabel->height + 2;

	toggleButton->xPosition = width / 2;
	toggleButton->yPosition = testButton->yPosition + testButton->height + 2;

	container->xPosition = width / 2;
	container->yPosition = toggleButton->yPosition + toggleButton->height + 2;
	container->width = width / 2 - 6 - 2;
	container->height = height - container->yPosition - 6 - 2;
}

bool TestScreen::handleBackEvent(bool b)
{
	if (!b)
		mc->setScreen(new Touch::StartMenuScreen());
	return true;
}

void TestScreen::buttonClicked(Button *button)
{
	switch (button->id)
	{
	case 0:
		mc->setScreen(new Touch::StartMenuScreen());
		break;
	case 1:
		stateLabel->setTextRaw("누름 : BlankButton");
		break;
	case 2:
		stateLabel->setTextRaw("누름 : ImageButton");
		break;
	case 3:
		stateLabel->setTextRaw("누름 : TButton");
		break;
	case 4:
		stateLabel->setTextRaw("누름 : Toggle TButton");
		break;
	}
}
