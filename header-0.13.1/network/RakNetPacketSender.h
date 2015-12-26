#pragma once

#include "minecraftpe/network/PacketSender.h"

class RakNetPacketSender : public PacketSender
{
public:
	virtual ~RakNetPacketSender();
	virtual void send(Packet const &);
	virtual void send(RakNet::RakNetGUID const &, Packet const &);
	virtual void sendBroadcast(RakNet::RakNetGUID const &, Packet const &);
};
