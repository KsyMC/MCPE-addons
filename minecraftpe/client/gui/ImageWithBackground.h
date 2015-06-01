#pragma once

#include "LargeImageButton.h"

class Textures;

// Size : 244
class ImageWithBackground : public LargeImageButton
{
public:
	ImageWithBackground(int);
	virtual ~ImageWithBackground();
	virtual void render(MinecraftClient *, int, int);
	virtual void renderBg(MinecraftClient *, int, int);
	void init(Textures *, int, int, IntRectangle, IntRectangle, int, int, const std::string &);
	void setSize(float, float);
};
