#pragma once

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/block/BlockPos.h"
#include "minecraftpe/util/Vec3.h"
#include "minecraftpe/item/ItemInstance.h"

class UseItemPacket : public Packet
{
public:
	BlockPos pos;			// 16
	unsigned char face;		// 28
	Vec3 entityPos;			// 32
	Vec3 fPos;				// 44
	ItemInstance item;		// 56

	virtual ~UseItemPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
