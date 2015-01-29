#ifndef __MESSAGEPACKET_H__
#define __MESSAGEPACKET_H__

#include "Packet.h"
#include "../raknet/RakString.h"

namespace RakNet {
	class BitStream;
	class RakNetGUID;
}
class NetEventCallback;

class MessagePacket : public Packet {
public:
	RakNet::RakString _name;			// 12
	RakNet::RakString _message;		// 16

public:
	MessagePacket(const std::string &name, const std::string &message) {
		_name = name.c_str();
		_message = message.c_str();
	}
	virtual ~MessagePacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};

#endif
