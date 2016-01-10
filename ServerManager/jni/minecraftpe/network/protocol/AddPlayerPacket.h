#pragma once

#include "minecraftpe/network/Packet.h"

class Player;

// Size : 120
class AddPlayerPacket : public Packet
{
public:
	char filler[104];	// 16

	AddPlayerPacket(const Player &);
	virtual ~AddPlayerPacket();
	virtual int getId() const ;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
