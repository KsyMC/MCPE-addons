#include <vector>

#include "AddonManager.h"

#include "Addon.h"

#include "shared.h"

void AddonManager::registerAddon(Addon *addon)
{
	addon->onEnable();
	addons.push_back(addon);
}

bool AddonManager::isExist(const std::string &name)
{
	for (auto addon : addons)
	{
		if (!name.compare(addon->getName()))
			return true;
	}
	return false;
}
