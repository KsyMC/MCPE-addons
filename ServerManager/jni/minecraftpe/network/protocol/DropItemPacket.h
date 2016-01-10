#pragma once

#include "minecraftpe/network/Packet.h"

// Size : 36
class DropItemPacket : public Packet
{
public:
	bool drop;			// 13
	ItemInstance item;	// 16

	virtual ~DropItemPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
