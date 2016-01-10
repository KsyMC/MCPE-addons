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

	char type;							// 13
	std::string source;					// 16
	std::string message;				// 20
	std::vector<std::string> params;	// 24

	virtual ~TextPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
