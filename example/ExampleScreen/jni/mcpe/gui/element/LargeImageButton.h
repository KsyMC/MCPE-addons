#ifndef __LARGEIMAGEBUTTON_H__
#define __LARGEIMAGEBUTTON_H__

#include "ImageButton.h"

class MinecraftClient;
struct ImageDef;

class LargeImageButton : public ImageButton {
public:
	// Size : 196

public:
	LargeImageButton(const std::string &);
	LargeImageButton(const std::string &, ImageDef &);
	virtual ~LargeImageButton();
	virtual void render(MinecraftClient *, int, int);
	virtual void setupDefault();
};

#endif
