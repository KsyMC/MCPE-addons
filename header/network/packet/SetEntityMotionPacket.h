#pragma once

#include "../Packet.h"

class SetEntityMotionPacket : public Packet
{
public:
	virtual ~SetEntityMotionPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
