#pragma once

#include "minecraftpe/ItemInstance.h"
#include "minecraftpe/network/Packet.h"

class ContainerSetSlotPacket : public Packet {
public:
	// Size : 36
	// TODO 					// 12
	ItemInstance _itemInstance;	// 16

public:
	virtual ~ContainerSetSlotPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);

};
