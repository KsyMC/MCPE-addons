#pragma once

#include "TButton.h"

namespace Touch
{

// Size : 188
class HeaderButton : public TButton
{
public:
	HeaderButton(int, MinecraftClient &, const std::string &, bool, bool);
	virtual ~HeaderButton();
	virtual void setMsg(const std::string &);
};

}