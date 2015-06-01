#pragma once

#include "Button.h"

namespace Touch
{

// Size : 176
class TButton : public Button
{
public:
	NinePatchLayer *_ninepathLayer1;		// 168
	NinePatchLayer *_ninepathLayer2;		// 172

public:
	TButton(int, int, int, int, int, const std::string &, MinecraftClient *, bool);
	TButton(int, int, int, const std::string &, MinecraftClient *);
	TButton(int, const std::string &, MinecraftClient *, bool);
	virtual ~TButton();
	virtual void renderBg(MinecraftClient *, int, int);
	void init(MinecraftClient *);
	void init(MinecraftClient *, const std::string &, const IntRectangle &, const IntRectangle &, int, int, int, int);
};

}
