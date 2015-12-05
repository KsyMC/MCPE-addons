#pragma once

#include "Player.h"

// Size : 3448
class RemotePlayer : public Player
{
public:
	RemotePlayer(BlockSource &, PacketSender &, bool, const RakNet::RakNetGUID &);
	virtual ~RemotePlayer();
	virtual void normalTick();
	virtual void aiStep();
	virtual void tickWorld(const Tick &);
};
