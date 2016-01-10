#pragma once

#include "minecraftpe/network/Packet.h"

// Size : 28
class BatchPacket : public Packet
{
public:
	virtual ~BatchPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
	void add(const Packet *);
	void compress();
};
