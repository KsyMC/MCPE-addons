#pragma once

#include <raknet/RakNetTypes.h>

class Packet;

class PacketSender
{
public:
	virtual ~PacketSender();
	virtual void send(const Packet &) = 0;
	virtual void send(const RakNet::RakNetGUID &, const Packet &) = 0;
	virtual void sendBroadcast(const RakNet::RakNetGUID &, const Packet &) = 0;
};
