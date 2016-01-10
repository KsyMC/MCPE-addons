#pragma once

#include <vector>

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/item/ItemInstance.h"

// Size : 40
class ContainerSetContentPacket : public Packet
{
public:
	unsigned char windowId;				// 13
	std::vector<ItemInstance> slots;	// 16
	std::vector<int> hotbar;			// 28

	virtual ~ContainerSetContentPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
