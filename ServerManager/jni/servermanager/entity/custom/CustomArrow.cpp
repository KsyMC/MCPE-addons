#include "servermanager/entity/custom/CustomArrow.h"
#include "servermanager/ServerManager.h"
#include "servermanager/event/player/PlayerPickupItemEvent.h"
#include "servermanager/plugin/PluginManager.h"
#include "minecraftpe/entity/Arrow.h"
#include "minecraftpe/entity/player/Inventory.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/item/Item.h"
#include "hook/Substrate.h"
#include "log.h"

FUNCTION_HOOK_CPP(void, CustomArrow, playerTouch, Arrow *real, Player &player)
{
	if(!real->level->isClientSide() && real->getEnchantInfinity() == 0)
	{
		ItemInstance arrowItem(Item::mArrow, 1);
		if(!real->onGround || !real->fromPlayer || real->shakeTime > 0 || player.inventory->canAdd(arrowItem))
			return;

		PlayerPickupItemEvent event((SMPlayer *)ServerManager::getEntity(&player), &arrowItem, 0);
		ServerManager::getPluginManager()->callEvent(event);

		if(event.isCancelled())
			return;
	}
	playerTouch_real(real, player);
}

void CustomArrow::setupHooks()
{
	MSHookFunction((void *)&Arrow::playerTouch, (void *)&playerTouch, (void **)&playerTouch_real);
}
