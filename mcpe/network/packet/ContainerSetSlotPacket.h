#ifndef __CONTAINERSETSLOTPACKET_H__
#define __CONTAINERSETSLOTPACKET_H__

#include "../../ItemInstance.h"
#include "Packet.h"

namespace RakNet {
	class BitStream;
	class RakNetGUID;
}
class NetEventCallback;

class ContainerSetSlotPacket : public Packet {
public:
	// Size : 36
	// TODO 							// 12
	ItemInstance _itemInstance;	// 16

public:
	ContainerSetSlotPacket() {}
	virtual ~ContainerSetSlotPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);

};

#endif
