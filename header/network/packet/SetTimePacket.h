#pragma once

#include "../Packet.h"

class SetTimePacket : public Packet
{
public:
	virtual ~SetTimePacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
