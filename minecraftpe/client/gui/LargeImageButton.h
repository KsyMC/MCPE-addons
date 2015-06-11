#pragma once

#include "ImageButton.h"

// Size : 244
class LargeImageButton : public ImageButton
{
public:
	LargeImageButton(const std::string &);
	LargeImageButton(const std::string &, ImageDef &);
	virtual ~LargeImageButton();
	virtual void render(MinecraftClient *, int, int);
	virtual void setupDefault();
};
