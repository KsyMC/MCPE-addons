#pragma once

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/item/ItemInstance.h"

// Size : 40
class ContainerSetSlotPacket : public Packet
{
public:
	unsigned char windowId;		// 13
	short slot;					// 14
	short hotbarSlot;			// 16
	ItemInstance item;			// 20

	virtual ~ContainerSetSlotPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(RakNet::RakNetGUID const &, NetEventCallback *) const;
};
