#pragma once

#include "../Packet.h"
#include "../../util/TilePos.h"

class UpdateBlockPacket : public Packet
{
public:
	TilePos pos;			// 12
	unsigned char id;		// 24
	unsigned char damage;	// 25

public:
	virtual ~UpdateBlockPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
