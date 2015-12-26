#pragma once

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/item/ItemInstance.h"

// Size : 40
class ContainerSetContentPacket : public Packet
{
public:
	unsigned char windowId;				// 13
	vector<ItemInstance> slots;			// 16
	vector<int> hotbar;					// 28

	virtual ~ContainerSetContentPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(RakNet::RakNetGUID const &, NetEventCallback *) const;
};
