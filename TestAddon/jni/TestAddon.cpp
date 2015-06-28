#include "TestAddon.h"

TestAddon::TestAddon()
{

}

TestAddon::~TestAddon()
{

}

std::string TestAddon::getName()
{
	return "TestAddon";
}

std::string TestAddon::getVersion()
{
	return "V1.0";
}

int TestAddon::getVersionCode()
{
	return 1;
}

std::string TestAddon::getDescription()
{
	return "테스트 애드온";
}
