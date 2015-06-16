#pragma once

#include "../Packet.h"

class SetDifficultyPacket : public Packet
{
public:
	virtual ~SetDifficultyPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
