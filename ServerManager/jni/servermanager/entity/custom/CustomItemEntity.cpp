#include "servermanager/entity/custom/CustomItemEntity.h"
#include "servermanager/ServerManager.h"
#include "servermanager/event/player/PlayerPickupItemEvent.h"
#include "servermanager/plugin/PluginManager.h"
#include "minecraftpe/entity/ItemEntity.h"
#include "minecraftpe/entity/player/Inventory.h"
#include "minecraftpe/level/Level.h"
#include "hook/Substrate.h"

FUNCTION_HOOK_CPP(void, CustomItemEntity, playerTouch, ItemEntity *real, Player &player)
{
	if(!real->level->isClientSide())
	{
		int canHold = real->item.count;/*player.inventory->_getSlotWithRemainingSpace(real->item);*/
		int remaining = real->item.count - canHold;

		if(!player.isAlive() || real->pickupDelay > 0 || canHold <= 0 || !player.inventory->canAdd(real->item))
			return;

		real->item.count = canHold;
		PlayerPickupItemEvent event((SMPlayer *)ServerManager::getEntity(&player), &real->item, remaining);
		ServerManager::getPluginManager()->callEvent(event);
		real->item.count = canHold + remaining;

		if(event.isCancelled())
			return;
	}
	playerTouch_real(real, player);
}

void CustomItemEntity::setupHooks()
{
	MSHookFunction((void *)&ItemEntity::playerTouch, (void *)&playerTouch, (void **)&playerTouch_real);
}
