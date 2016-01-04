#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class ToogleDownFallCommand : public VanillaCommand
{
public:
	ToogleDownFallCommand();

	bool execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args);
};
