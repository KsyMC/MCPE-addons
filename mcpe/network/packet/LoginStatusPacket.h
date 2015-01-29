#ifndef __LOGINSTATUSPACKET_H__
#define __LOGINSTATUSPACKET_H__

#include "Packet.h"

namespace RakNet {
	class BitStream;
	class RakNetGUID;
}
class NetEventCallback;

class LoginStatusPacket : public Packet {
public:
	int _status;	// 12

public:
	LoginStatusPacket(int status) {
		_status = status;
	};
	virtual ~LoginStatusPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};

#endif
