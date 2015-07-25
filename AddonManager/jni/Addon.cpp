#include "Addon.h"

Addon::Addon()
{

}

Addon::~Addon()
{

}

void Addon::onEnable()
{

}

void Addon::onDisable()
{

}

Screen *Addon::getOptionsScreen(Screen *backScreen)
{
	return NULL;
}

std::string Addon::getName()
{
	return "Unknown";
}

std::string Addon::getVersion()
{
	return "Unknown";
}

int Addon::getVersionCode()
{
	return -1;
}

std::string Addon::getDescription()
{
	return "";
}
