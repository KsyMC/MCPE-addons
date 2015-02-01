#pragma once

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/raknet/RakString.h"

namespace RakNet {
class RakString;
}

class ChatPacket : public Packet {
public:
	RakNet::RakString _chat;	// 12

public:
	virtual ~ChatPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};
