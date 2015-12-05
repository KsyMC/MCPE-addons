#pragma once

#include "../Packet.h"

class ContainerSetDataPacket : public Packet
{
public:
	virtual ~ContainerSetDataPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
