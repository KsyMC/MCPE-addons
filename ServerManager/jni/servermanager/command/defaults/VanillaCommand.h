#pragma once

#include "servermanager/command/Command.h"

class VanillaCommand : public Command
{
public:
	static int MAX_COORD;
	static int MIN_COORD;

public:
	VanillaCommand(const std::string &name, const std::string &description = "", const std::string &usageMessage = "", const std::vector<std::string> &aliases = {});

	virtual bool isVanillaCommand() const;

protected:
	int getInteger(SMPlayer *sender, const std::string &value, int min = MIN_COORD, int max = MAX_COORD) const;
	double getRelativeDouble(double original, SMPlayer *player, std::string &input, double min = MIN_COORD, double max = MAX_COORD) const;
	double getDouble(SMPlayer *sender, const std::string &value, double min = MIN_COORD, double max = MAX_COORD) const;
};
