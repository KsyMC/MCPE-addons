#pragma once

#include "../Packet.h"

class AdventureSettings;
class Abilities;

class AdventureSettingsPacket : public Packet
{
public:
	AdventureSettingsPacket(const AdventureSettings &, const Abilities &);
	virtual ~AdventureSettingsPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
