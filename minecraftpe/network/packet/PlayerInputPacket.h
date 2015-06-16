#pragma once

#include "../Packet.h"

class PlayerInputPacket : public Packet
{
public:
	virtual ~PlayerInputPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
