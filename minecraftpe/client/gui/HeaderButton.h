#pragma once

#include "TButton.h"

namespace Touch
{
// Size : 128
class HeaderButton : public TButton
{
public:
	char filler1[12];		// 116

public:
	HeaderButton(int, MinecraftClient &, std::string const &, bool, bool);
	virtual ~HeaderButton();
	virtual void setMsg(std::string const &);
};
};
