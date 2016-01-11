#pragma once

#include "servermanager/command/defaults/VanillaCommand.h"

class TeleportCommand : public VanillaCommand
{
public:
	TeleportCommand();

	bool execute(SMPlayer *player, std::string &label, std::vector<std::string> &args);

private:
	double getCoordinate(SMPlayer *sender, double current, std::string &input, int max = MAX_COORD, int min = MIN_COORD);
};
