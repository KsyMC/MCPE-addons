#pragma once

#include "shared.h"

class Packet;

class PacketSender
{
public:
	virtual ~PacketSender();
	virtual void send(Packet const &) = 0;
	virtual void send(RakNet::RakNetGUID const &, Packet const &) = 0;
	virtual void sendBroadcast(RakNet::RakNetGUID const &, Packet const &) = 0;
};
