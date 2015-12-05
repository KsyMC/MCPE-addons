#pragma once

class IRakNetInstance;
class Packet;

namespace RakNet
{
	class RakNetGUID;
}

class PacketSender
{
public:
	virtual ~PacketSender();
	virtual void send(const Packet &) = 0;
	virtual void send(const RakNet::RakNetGUID &, const Packet &) = 0;
	virtual void sendBroadcast(const RakNet::RakNetGUID &, const Packet &) = 0;
};