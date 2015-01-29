#ifndef __PACKET_H__
#define __PACKET_H__

namespace RakNet {
	class BitStream;
	class RakNetGUID;
}
class NetEventCallback;

class Packet {
public:
	//void **vtable;	// 0
	int wtf1;			// 4
	int wtf2;			// 8

public:
	Packet();
	virtual ~Packet();
	virtual void write(RakNet::BitStream *) = 0;
	virtual void read(RakNet::BitStream *) = 0;
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) = 0;
};

#endif
