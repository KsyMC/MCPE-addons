#pragma once

#include "../Packet.h"

class Player;

class PlayerArmorEquipmentPacket : public Packet
{
public:
	PlayerArmorEquipmentPacket(Player *);
	virtual ~PlayerArmorEquipmentPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
