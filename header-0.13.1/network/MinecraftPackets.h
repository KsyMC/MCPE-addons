#pragma once

#include <memory>

#include "minecraftpe/network/Packet.h"

class MinecraftPackets
{
public:
	static std::unique_ptr<Packet> createPacket(int);
};
