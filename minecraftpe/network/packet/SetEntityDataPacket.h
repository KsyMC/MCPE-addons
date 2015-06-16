#pragma once

#include "../Packet.h"

class SetEntityDataPacket : public Packet
{
public:
	virtual ~SetEntityDataPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
