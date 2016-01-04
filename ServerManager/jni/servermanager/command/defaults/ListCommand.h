#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class ListCommand : public VanillaCommand
{
public:
	ListCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);
};
