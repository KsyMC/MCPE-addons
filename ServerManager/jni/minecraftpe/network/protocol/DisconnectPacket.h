#pragma once

#include "minecraftpe/network/Packet.h"

// Size : 20
class DisconnectPacket : public Packet
{
public:
	std::string message;	// 16

	virtual ~DisconnectPacket();
	virtual int getId() const ;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
