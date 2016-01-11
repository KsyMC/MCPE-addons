#include "servermanager/command/defaults/VanillaCommand.h"
#include "servermanager/util/SMUtil.h"

int VanillaCommand::MAX_COORD = 30000000;
int VanillaCommand::MIN_COORD_MINUS_ONE = -30000001;
int VanillaCommand::MIN_COORD = -30000000;

VanillaCommand::VanillaCommand(const std::string &name, const std::string &description, const std::string &usageMessage, const std::vector<std::string> &aliases)
	: Command(name, description, usageMessage, aliases)
{
}

bool VanillaCommand::isVanillaCommand() const
{
	return true;
}

int VanillaCommand::getInteger(SMPlayer *sender, const std::string &value, int min, int max) const
{
	int i = SMUtil::toInt(value);
	if(i < min)
		i = min;
	else if(i > max)
		i = max;

	return i;
}

double VanillaCommand::getRelativeDouble(double original, SMPlayer *sender, std::string &input) const
{
	if(input[0] == '~')
		return original + SMUtil::toDouble(input.erase(0, 1));
	return getDouble(sender, input);
}

double VanillaCommand::getDouble(SMPlayer *sender, const std::string &value, double min, double max) const
{
	double result = SMUtil::toDouble(value.c_str());
	if(result < min)
		result = min;
	else if(result > max)
		result = max;

	return result;
}
