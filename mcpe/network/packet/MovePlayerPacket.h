#ifndef __MOVEPLAYERPACKET_H__
#define __MOVEPLAYERPACKET_H__

#include "Packet.h"

namespace RakNet {
	class BitStream;
	class RakNetGUID;
}
class NetEventCallback;

class MovePlayerPacket : public Packet {
public:
	// Size : 44
	uint _eid; 		// 12
	float _x;			// 16
	float _y;			// 20
	float _z;			// 24
	float _bodyYaw;	// 28
	float _pitch;		// 32
	float _yaw;		// 36
	bool _teleport;	// 40

public:
	MovePlayerPacket(uint eid, float x, float y, float z, float bodyYaw, float pitch, float yaw, bool teleport) {
		_eid = eid;
		_x = x;
		_y = y;
		_z = z;
		_bodyYaw = bodyYaw;
		_pitch = pitch;
		_yaw = yaw;
		_teleport = teleport;
	}
	virtual ~MovePlayerPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};

#endif
