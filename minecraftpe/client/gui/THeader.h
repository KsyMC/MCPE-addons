#pragma once

#include "Button.h"

namespace Touch
{

// Size : 172
class THeader : public Button
{
public:
	char filler1[4];	// 168

public:
	THeader(int, int, int, int, int, const std::string &);
	THeader(int, int, int, const std::string &);
	THeader(int, const std::string &);
	virtual ~THeader();
	virtual void render(MinecraftClient *, int, int);
	virtual void renderBg(MinecraftClient *, int, int);
};

}