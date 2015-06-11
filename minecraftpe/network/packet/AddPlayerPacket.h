#pragma once

#include "../Packet.h"

class Player;

class AddPlayerPacket : public Packet
{
public:
	AddPlayerPacket(const Player &);
	virtual ~AddPlayerPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
