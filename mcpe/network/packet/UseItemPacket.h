#ifndef __USEITEMPACKET_H__
#define __USEITEMPACKET_H__

#include "Packet.h"
#include "../../ItemInstance.h"

class UseItemPacket : public Packet {
public:
	int _x;								// 12
	int _y;								// 16
	int _z;								// 20
	char _face;						// 24
	float _posX;						// 28
	float _posY;						// 32
	float _posZ;						// 36
	float _fx;							// 40
	float _fy;							// 44
	float _fz;							// 48
	int _eid;							// 52
	short _item;						// 56
	unsigned short _meta;			// 58
	ItemInstance _itemInstance;	// 60

public:
	UseItemPacket(int x, int y, int z, char face, float posX, float posY, float posZ, float fx, float fy, float fz, int eid, short item, short meta) {
		_x = x;
		_y = y;
		_z = z;
		_face = face;
		_posX = posX;
		_posY = posY;
		_posZ = posZ;
		_fx = fx;
		_fy = fy;
		_fz = fz;
		_eid = eid;
		_item = item;
		_meta = meta;
	}
	virtual ~UseItemPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};

#endif
