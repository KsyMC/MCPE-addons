#pragma once

#include "minecraftpe/network/PacketSender.h"

class RakNetPacketSender : public PacketSender
{
public:
	virtual ~RakNetPacketSender();
	virtual void send(const Packet &);
	virtual void send(const RakNet::RakNetGUID &, const Packet &);
	virtual void sendBroadcast(const RakNet::RakNetGUID &, const Packet &);
};
