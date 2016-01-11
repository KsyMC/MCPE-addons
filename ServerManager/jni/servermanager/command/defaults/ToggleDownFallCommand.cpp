#include "servermanager/command/defaults/ToogleDownFallCommand.h"

ToogleDownFallCommand::ToogleDownFallCommand()
	: VanillaCommand("toggledownfall")
{

}

bool ToogleDownFallCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	return true;
}
