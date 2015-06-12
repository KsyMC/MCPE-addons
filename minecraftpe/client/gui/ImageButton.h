#pragma once

#include "Button.h"
#include "ImageDef.h"

// Size : 244
class ImageButton : public Button
{
public:
	ImageDef imageDef;	// 168
	char filler1[20];	// 208
	int yOffset;		// 228
	char filler2[12];	// 232

public:
	ImageButton(int, const std::string &);
	ImageButton(int, const std::string &, const ImageDef &);
	virtual ~ImageButton();
	virtual void render(MinecraftClient *, int, int);
	virtual void renderBg(MinecraftClient *, int, int);
	virtual void setYOffset(int);
	virtual void setupDefault();
	virtual void isSecondImage(bool);
	void setImageDef(const ImageDef &, bool);
};
