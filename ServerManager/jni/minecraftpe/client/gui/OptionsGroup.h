#pragma once

#include "minecraftpe/client/gui/GuiElementContainer.h"
#include "minecraftpe/client/settings/Options.h"

class OptionsGroup : public GuiElementContainer
{
public:
	OptionsGroup(std::string, bool);
	virtual ~OptionsGroup();
	virtual void render(MinecraftClient *, int, int);
	virtual void setupPositions();
	virtual void addOptionItem(const Options::Option &, MinecraftClient &);
	virtual void addLimitedTextBoxOptionItem(const Options::Option &, MinecraftClient &, const std::string &);
	virtual void optionalAddOptionItem(bool, const Options::Option &, MinecraftClient &);
	virtual void createToggle(const Options::Option &, MinecraftClient &);
	virtual void createProgressSlider(const Options::Option &, MinecraftClient &);
	virtual void createStepSlider(const Options::Option &, MinecraftClient &);
	void createTextBox(const Options::Option &, MinecraftClient &, const std::string &);
};
