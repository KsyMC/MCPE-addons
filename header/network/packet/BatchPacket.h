#pragma once

#include "../Packet.h"

class BatchPacket : public Packet
{
public:
	static void *compressor;

public:
	virtual ~BatchPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
