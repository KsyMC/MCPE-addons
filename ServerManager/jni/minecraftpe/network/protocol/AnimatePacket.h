#pragma once

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/entity/EntityUniqueID.h"

// Size : 32
class AnimatePacket : public Packet
{
public:
	EntityUniqueID uniqueID;	// 16
	unsigned char action;		// 24

	virtual ~AnimatePacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
