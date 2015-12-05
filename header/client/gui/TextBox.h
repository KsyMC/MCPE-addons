#pragma once

#include "GuiElement.h"
#include "../settings/Options.h"

namespace Touch
{
	class TButton;
};

class Screen;

// Size : 100
class TextBox : public GuiElement
{
public:
	static const char *extendedASCII;
	static const char *identifierChars;
	static const char *numberChars;

public:
	char filler1[52];	// 48

public:
	TextBox(MinecraftClient &, const Options::Option *, const std::string &, const std::string &);
	TextBox(MinecraftClient &, const std::string &, int, const std::string &, Screen *, void (Screen::*)(int), int, bool);
	virtual ~TextBox();
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void topRender(MinecraftClient *, int, int);
	virtual void pointerPressed(MinecraftClient *, int, int);
	virtual void pointerReleased(MinecraftClient *, int, int);
	virtual void focusedMouseClicked(MinecraftClient *, int, int);
	virtual void focusedMouseReleased(MinecraftClient *, int, int);
	virtual void handleButtonRelease(MinecraftClient *, short);
	virtual void handleTextChar(MinecraftClient *, std::string const &, bool);
	virtual void backPressed(MinecraftClient *, bool);
	virtual void suppressOtherGUI();
	virtual void setTextboxText(std::string const &);
	virtual void hasFocus() const;
	virtual void setFocus(MinecraftClient *);
	virtual void loseFocus(MinecraftClient *);
	int getKey();
	std::string &getText() const;
	void setText(const std::string &);
	void setValidChars(const std::string &);
};
