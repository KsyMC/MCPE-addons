#pragma once

#include "TButton.h"

namespace Touch
{

// Size : 188
class HeaderButton : public TButton
{
public:
	char filler1[12];	// 176

public:
	HeaderButton(int, MinecraftClient &, const std::string &, bool, bool);
	virtual ~HeaderButton();
	virtual void setMsg(const std::string &);
};

}
