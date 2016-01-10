#pragma once

#include "minecraftpe/network/Packet.h"

class Entity;

// Size : 88
class AddEntityPacket : public Packet
{
public:
	char filler[72];	// 16

	AddEntityPacket(const Entity &);
	virtual ~AddEntityPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
