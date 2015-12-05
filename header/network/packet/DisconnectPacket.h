#pragma once

#include "../Packet.h"

class DisconnectPacket : public Packet
{
public:
	virtual ~DisconnectPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
