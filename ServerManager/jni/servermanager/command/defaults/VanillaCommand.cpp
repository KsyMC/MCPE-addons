#include "servermanager/command/defaults/VanillaCommand.h"
#include "servermanager/util/SMUtil.h"

int VanillaCommand::MAX_COORD = 30000000;
int VanillaCommand::MIN_COORD = -30000000;

VanillaCommand::VanillaCommand(const std::string &name, const std::string &description, const std::string &usageMessage, const std::vector<std::string> &aliases)
	: Command(name, description, usageMessage, aliases)
{
}

bool VanillaCommand::isVanillaCommand() const
{
	return true;
}

int VanillaCommand::getInteger(SMPlayer *player, const std::string &value, int min, int max) const
{
	int result = SMUtil::toInt(value);

	if(result < min)
		result = min;
	else if(result > max)
		result = max;

	return result;
}

double VanillaCommand::getRelativeDouble(double original, SMPlayer *player, std::string &input, double min, double max) const
{
	if(input[0] == '~')
	{
		return original + getDouble(player, input.erase(0, 1), min, max);
	}
	return getDouble(player, input, min, max);
}

double VanillaCommand::getDouble(SMPlayer *player, const std::string &value, double min, double max) const
{
	double result = SMUtil::toDouble(value.c_str());

	if(result < min)
		result = min;
	else if(result > max)
		result = max;

	return result;
}
