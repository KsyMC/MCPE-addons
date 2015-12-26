#pragma once

#include "minecraftpe/network/Packet.h"

// Size : 36
class TextPacket : public Packet
{
public:
	enum Type
	{
		TYPE_RAW,
		TYPE_CHAT,
		TYPE_TRANSLATION,
		TYPE_POPUP,
		TYPE_TIP,
		TYPE_SYSTEM
	};

	char type;				// 13
	string source;			// 16
	string message;			// 20
	vector<string> params;	// 24

	virtual ~TextPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(RakNet::RakNetGUID const &, NetEventCallback *) const;
};
