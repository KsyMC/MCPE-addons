#pragma once

#include "../Packet.h"

class Entity;

class AddEntityPacket : public Packet
{
public:
	AddEntityPacket(Entity &);
	virtual ~AddEntityPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
