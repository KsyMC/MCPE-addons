#pragma once

#include "../Packet.h"
#include "../../item/ItemInstance.h"

class UseItemPacket : public Packet
{
public:
	int x;						// 12
	int y;						// 16
	int z;						// 20
	unsigned char face;			// 24
	float posX;					// 28
	float posY;					// 32
	float posZ;					// 36
	float fx;					// 40
	float fy;					// 44
	float fz;					// 48
	int eid;					// 52
	short item;					// 56
	unsigned short meta;		// 58
	ItemInstance itemInstance;	// 60

public:
	virtual ~UseItemPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
