#pragma once

#include "../Packet.h"

class TextPacket : public Packet
{
public:
	virtual ~TextPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
