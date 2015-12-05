#pragma once

#include "ImageButton.h"

// Size : 180
class LargeImageButton : public ImageButton
{
public:
	LargeImageButton(int, std::string const &);
	LargeImageButton(int, std::string const &, ImageDef &);
	virtual ~LargeImageButton();
	virtual void render(MinecraftClient *, int, int);
	virtual void setupDefault();
};
