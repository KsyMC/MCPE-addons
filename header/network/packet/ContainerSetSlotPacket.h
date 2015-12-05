#pragma once

#include "../Packet.h"
#include "../../item/ItemInstance.h"

// Size : 36
class ContainerSetSlotPacket : public Packet
{
public:
	// TODO 					// 12
	ItemInstance itemInstance;	// 16

public:
	virtual ~ContainerSetSlotPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
