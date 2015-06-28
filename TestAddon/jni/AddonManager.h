#pragma once

#include <string>

class Addon;

class AddonManager
{
public:
	static void registerAddon(Addon *addon);
	static bool isExist(const std::string &name);
};
