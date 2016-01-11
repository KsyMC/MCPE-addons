#pragma once

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/entity/EntityUniqueID.h"
#include "minecraftpe/block/BlockPos.h"

class RemoveBlockPacket : public Packet
{
public:
	EntityUniqueID uniqueID;	// 16
	BlockPos pos;				// 24

	virtual ~RemoveBlockPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
