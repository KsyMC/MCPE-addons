#pragma once

#include "PacketSender.h"

class NetEventCallback;

namespace RakNet
{
	class AddressOrGUID;
}

// Size : 24
class RakNetPacketSender : public PacketSender
{
public:
	RakNetPacketSender(IRakNetInstance &);
	virtual ~RakNetPacketSender();
	virtual void send(const Packet &);
	virtual void send(const RakNet::RakNetGUID &, const Packet &);
	virtual void sendBroadcast(const RakNet::RakNetGUID &, const Packet &);
	void addLoopbackCallback(NetEventCallback &);
	void removeLoopbackCallback(NetEventCallback &);
	void sendInternal(const RakNet::AddressOrGUID &, const Packet &, bool);
};