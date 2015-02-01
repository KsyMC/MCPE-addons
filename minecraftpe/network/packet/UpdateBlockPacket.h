#pragma once

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/tile/TilePos.h"

class Vec3;

class UpdateBlockPacket : public Packet {
public:
	TilePos _pos;			// 12
	unsigned char _id;		// 24
	unsigned char _damage;	// 25

public:
	virtual ~UpdateBlockPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};
