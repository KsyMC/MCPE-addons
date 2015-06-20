#include "TestListItemElement.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/gui/TButton.h"
#include "minecraftpe/client/gui/ImageWithBackground.h"
#include "minecraftpe/client/gui/IntRectangle.h"
#include "minecraftpe/client/gui/Font.h"
#include "minecraftpe/client/gui/Gui.h"
#include "minecraftpe/client/gui/Mouse.h"
#include "shared.h"

#include <cmath>

TestListItemElement::TestListItemElement(MinecraftClient *mc) : GuiElement(true, true, 0, 0, 24, 24)
{
	mainButton = NULL;
	removeButton = NULL;
	clickedButton = NULL;
	clickedX = 0;
	clickedY = 0;

	height = 32;

	mainButton = new Touch::TButton(1, "Button", NULL, false, 0x7FFFFFFF);
	mainButton->init(mc, "gui/spritesheet.png", {8, 32, 8, 8}, {0, 32, 8, 8}, 2, 2, 120, 32);

	removeButton = new ImageWithBackground(-1);
	removeButton->init(mc->textures, 32, 32, {112, 0, 8, 67}, {120, 0, 8, 67}, 2, 2, "gui/spritesheet.png");
	removeButton->setImageDef({"gui/gui.png", 0, 0, 11, 11, {182, 10, 11, 11}, true}, false);
	removeButton->width = 32;
	removeButton->height = 32;
	removeButton->setupPositions();
}

TestListItemElement::~TestListItemElement()
{
	delete mainButton;
	delete removeButton;
}

void TestListItemElement::tick(MinecraftClient *mc)
{
	float scale = Gui::InvGuiScale;
	float mouseX = Mouse::getX() * scale;
	float mouseY = Mouse::getY() * scale;

	if (fabsf(mouseX - clickedX) > 20.0f || fabsf(mouseY - clickedY) > 20.0f)
	{
		if (clickedButton == mainButton)
			mainButton->released(mouseX, mouseY);
		else if (clickedButton == removeButton)
			removeButton->released(mouseX, mouseY);

		clickedButton = NULL;
	}
}

void TestListItemElement::render(MinecraftClient *mc, int x, int y)
{
	mainButton->xPosition = xPosition;
	mainButton->yPosition = yPosition;
	mainButton->width = width - removeButton->width;
	mainButton->render(mc, x, y);

	removeButton->xPosition = xPosition + width - removeButton->width;
	removeButton->yPosition = yPosition;
	removeButton->render(mc, x, y);

	mc->font->drawShadow("String", xPosition + 5, yPosition + 5, Color::YELLOW);
}

void TestListItemElement::mouseClicked(MinecraftClient *mc, int x, int y, int i)
{
	float scale = Gui::InvGuiScale;
	float mouseX = Mouse::getX() * scale;
	float mouseY = Mouse::getY() * scale;

	Button *tempButton = NULL;

	if (mainButton->clicked(mc, x, y))
		tempButton = mainButton;
	else if (removeButton->clicked(mc, x, y))
		tempButton = removeButton;

	if (tempButton)
	{
		LOGI("%d %d", mouseX, mouseY);

		clickedX = mouseX;
		clickedY = mouseY;
		tempButton->setPressed();
		clickedButton = tempButton;
	}
}

void TestListItemElement::mouseReleased(MinecraftClient *mc, int x, int y, int i)
{
	Button *tempButton = NULL;

	if (clickedButton == mainButton)
	{
		if (mainButton->clicked(mc, x, y))
		{
			LOGI("MainButton");
			mc->playUI("random.click", 1.0f, 1.0f);
		}
		else
			tempButton = mainButton;
	}
	else if (clickedButton == removeButton)
	{
		if (removeButton->clicked(mc, x, y))
		{
			LOGI("RemoveButton");
			mc->playUI("random.click", 1.0f, 1.0f);
		}
		else
			tempButton = removeButton;
	}

	if (tempButton)
	{
		tempButton->released(x, y);
		clickedButton = NULL;
	}
}
