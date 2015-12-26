#pragma once

#include "minecraftpe/network/Packet.h"

// Size : 20
class DisconnectPacket : public Packet
{
public:
	string message;		// 16

	virtual ~DisconnectPacket();
	virtual int getId() const ;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(RakNet::RakNetGUID const &, NetEventCallback *) const;
};
