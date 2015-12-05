#pragma once

#include "Button.h"

class NinePatchLayer;

namespace Touch
{
// Size : 116
class TButton : public Button
{
public:
	NinePatchLayer* unclickedNinePatchLayer;		// 108
	NinePatchLayer* clickedNinePatchLayer;			// 112

public:
	TButton(int, int, int, int, int, std::string const &, MinecraftClient *, bool, int);
	TButton(int, int, int, std::string const &, MinecraftClient *, int);
	TButton(int, std::string const &, MinecraftClient *, bool, int);
	virtual ~TButton();
	virtual void renderBg(MinecraftClient *, int, int);
	void init(MinecraftClient *);
	void init(MinecraftClient *, std::string const &, IntRectangle const &, IntRectangle const &, int, int, int, int);
};
};
