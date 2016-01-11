#pragma once

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/nbt/CompoundTag.h"

// Size : 60
class BlockEntityDataPacket : public Packet
{
public:
	BlockPos pos;
	CompoundTag dataTag;

	virtual ~BlockEntityDataPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
