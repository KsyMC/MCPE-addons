#pragma once

#include "minecraftpe/network/Packet.h"

// Size : 20
class PlayStatusPacket : public Packet
{
public:
	enum Status
	{
		LOGIN_SUCCESS,
		LOGIN_FAILED_CLIENT,
		LOGIN_FAILED_SERVER,
		PLAYER_SPAWN
	};

	int status;		// 16

	virtual ~PlayStatusPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const ;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
