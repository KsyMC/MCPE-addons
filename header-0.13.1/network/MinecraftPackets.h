#pragma once

#include "shared.h"
#include "minecraftpe/network/Packet.h"

class MinecraftPackets
{
public:
	static unique_ptr<Packet> createPacket(int);
};
