#pragma once

#include "../Packet.h"

class ItemEntity;

class AddItemEntityPacket : public Packet
{
public:
	AddItemEntityPacket(ItemEntity *);
	virtual ~AddItemEntityPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
