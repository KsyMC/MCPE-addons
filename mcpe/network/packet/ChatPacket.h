#ifndef __CHATPACKET_H__
#define __CHATPACKET_H__

#include "Packet.h"
#include "../raknet/RakString.h"

namespace RakNet {
	class BitStream;
	class RakNetGUID;
}
class NetEventCallback;

class ChatPacket : public Packet {
public:
	RakNet::RakString _chat;		// 12

public:
	ChatPacket() {};
	virtual ~ChatPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};

#endif
