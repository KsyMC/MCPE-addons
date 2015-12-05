#pragma once

#include "../Packet.h"

// Size : 44
class MovePlayerPacket : public Packet
{
public:
	uint eid; 		// 12
	float x;		// 16
	float y;		// 20
	float z;		// 24
	float bodyYaw;	// 28
	float pitch;	// 32
	float yaw;		// 36
	bool teleport;	// 40

public:
	virtual ~MovePlayerPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
