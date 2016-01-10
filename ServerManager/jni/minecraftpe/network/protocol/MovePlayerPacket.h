#pragma once

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/entity/EntityUniqueID.h"
#include "minecraftpe/util/Vec3.h"
#include "minecraftpe/util/Vec2.h"

// Size : 56
class MovePlayerPacket : public Packet
{
public:
	enum Mode
	{
		MODE_NORMAL,
		MODE_RESET,
		MODE_ROTATION
	};

	EntityUniqueID id;	// 16
	Vec3 pos;			// 24
	Vec2 rot;			// 36
	float bodyYaw;		// 44
	char mode;			// 48
	bool onGround;		// 49
	char filler[4];		// 52

	virtual ~MovePlayerPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
