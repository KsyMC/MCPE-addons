#pragma once

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/ItemInstance.h"

class UseItemPacket : public Packet {
public:
	int _x;						// 12
	int _y;						// 16
	int _z;						// 20
	unsigned char _face;		// 24
	float _posX;				// 28
	float _posY;				// 32
	float _posZ;				// 36
	float _fx;					// 40
	float _fy;					// 44
	float _fz;					// 48
	int _eid;					// 52
	short _item;				// 56
	unsigned short _meta;		// 58
	ItemInstance _itemInstance;	// 60

public:
	virtual ~UseItemPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};
