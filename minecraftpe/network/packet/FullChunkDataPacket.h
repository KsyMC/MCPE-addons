#pragma once

#include "../Packet.h"

class FullChunkDataPacket : public Packet
{
public:
	virtual ~FullChunkDataPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
