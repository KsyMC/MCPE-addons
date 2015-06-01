#pragma once

#include "Button.h"

class ImageDef;

// Size : 244
class ImageButton : public Button
{
public:
	char filler1[76];	// 168

public:
	ImageButton(int, const std::string &);
	ImageButton(int, const std::string &, const ImageDef &);
	virtual ~ImageButton();
	virtual void render(MinecraftClient *, int, int);
	virtual void renderBg(MinecraftClient *, int, int);
	virtual void setYOffset(int);
	virtual void setupDefault();
	virtual void isSecondImage(bool);
	bool isSecondImage(bool);
	void setImageDef(const ImageDef &, bool);
	void setYOffset(int);
	void setupDefault();
};
