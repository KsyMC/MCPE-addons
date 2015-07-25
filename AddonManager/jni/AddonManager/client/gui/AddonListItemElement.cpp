#include <cmath>

#include "AddonListItemElement.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/gui/TButton.h"
#include "minecraftpe/client/gui/IntRectangle.h"
#include "minecraftpe/client/gui/Font.h"
#include "minecraftpe/client/gui/Gui.h"
#include "minecraftpe/client/gui/Mouse.h"

#include "Addon.h"

AddonListItemElement::AddonListItemElement(MinecraftClient *mc, Addon *addon, std::function<void (Addon *)> f_setItem)
	: GuiElement(true, true, 0, 0, 24, 24)
{
	height = 16;
	mainButton = NULL;
	clickedButton = NULL;
	clickedX = 0;
	clickedY = 0;
	this->addon = addon;
	this->f_setItem = f_setItem;

	mainButton = new Touch::TButton(1, "", NULL, false, 0x7FFFFFFF);
	mainButton->init(mc, "gui/spritesheet.png", {8, 32, 8, 8}, {0, 32, 8, 8}, 2, 2, 0, 16);
}

AddonListItemElement::~AddonListItemElement()
{
	delete mainButton;
}

void AddonListItemElement::tick(MinecraftClient *mc)
{
	float scale = Gui::InvGuiScale;
	float mouseX = Mouse::getX() * scale;
	float mouseY = Mouse::getY() * scale;

	if (fabsf(mouseX - clickedX) > 20.0f || fabsf(mouseY - clickedY) > 20.0f)
	{
		if (clickedButton == mainButton)
			mainButton->released(mouseX, mouseY);

		clickedButton = NULL;
	}
}

void AddonListItemElement::render(MinecraftClient *mc, int x, int y)
{
	mainButton->width = width;
	mainButton->xPosition = xPosition;
	mainButton->yPosition = yPosition;
	mainButton->render(mc, x, y);

	mc->font->drawShadow(addon->getName() + " " + addon->getVersion(), xPosition + 4, yPosition + 4, Color::WHITE);
}

void AddonListItemElement::mouseClicked(MinecraftClient *mc, int x, int y, int i)
{
	float scale = Gui::InvGuiScale;
	float mouseX = Mouse::getX() * scale;
	float mouseY = Mouse::getY() * scale;

	if (mainButton->clicked(mc, x, y))
	{
		clickedX = mouseX;
		clickedY = mouseY;
		mainButton->setPressed();
		clickedButton = mainButton;
	}
}

void AddonListItemElement::mouseReleased(MinecraftClient *mc, int x, int y, int i)
{
	if (clickedButton == mainButton)
	{
		if (mainButton->clicked(mc, x, y))
		{
			mc->playUI("random.click", 1.0f, 1.0f);
			f_setItem(addon);
		}

		mainButton->released(x, y);
		clickedButton = NULL;
	}
}
