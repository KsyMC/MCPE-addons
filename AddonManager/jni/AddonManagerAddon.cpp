#include "AddonManagerAddon.h"

AddonManagerAddon::AddonManagerAddon()
{

}

AddonManagerAddon::~AddonManagerAddon()
{

}

Screen *AddonManagerAddon::getOptionsScreen(Screen *backScreen)
{
	return NULL;
}

std::string AddonManagerAddon::getName()
{
	return "AddonManager";
}

std::string AddonManagerAddon::getVersion()
{
	return "V1.0";
}

int AddonManagerAddon::getVersionCode()
{
	return 1;
}

std::string AddonManagerAddon::getDescription()
{
	return "애드온을 관리해줍니다";
}
