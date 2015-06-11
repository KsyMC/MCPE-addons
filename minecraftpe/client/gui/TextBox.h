#pragma once

#include "GuiElement.h"
#include "../settings/Options.h"

namespace Touch
{
	class TButton;
}

class Screen;

// Size : 164
class TextBox : public GuiElement
{
public:
	static const char *extendedAcsii;
	static const char *numberChars;

public:
	int key;					// 108
	Touch::TButton *doneButton;	// 112
	char filler1[12];			// 116
	std::string text;			// 128
	std::string titleText;		// 132
	bool isFocus;				// 136
	char filler2[7];			// 137
	const char *validChars;		// 144
	uint charsLength;			// 148
	char filler3[12];			// 152

public:
	TextBox(MinecraftClient *, const Options::Option *, const std::string &, const std::string &);
	TextBox(MinecraftClient *, const std::string &, int, const std::string &, Screen *, void (Screen::*)(int), int);
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void topRender(MinecraftClient *, int, int);
	virtual void mouseClicked(MinecraftClient *, int, int, int);
	virtual void mouseReleased(MinecraftClient *, int, int, int);
	virtual void focusedMouseClicked(MinecraftClient *, int, int, int);
	virtual void focusedMouseReleased(MinecraftClient *, int, int, int);
	virtual void keyPressed(MinecraftClient *, int);
	virtual void keyboardNewChar(MinecraftClient *, const std::string &, bool);
	virtual void backPressed(MinecraftClient *, bool);
	virtual void suppressOtherGUI();
	virtual void setTextboxText(const std::string &);
	virtual void setFocus(MinecraftClient *);
	virtual void loseFocus(MinecraftClient *);
	int getKey();
	std::string getText() const;
	void setText(const std::string &);
	void setValidChars(const std::string &);
};
