#pragma once

#include <string>

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/util/UUID.h"

// Size : 72
class LoginPacket : public Packet
{
public:
	std::string username;		// 16
	std::string clientSecret;	// 20
	std::string serverAddress;	// 24
	int filler;					// 28
	long long clientId;			// 32
	mce::UUID clientUUID;		// 40
	int protocol1;				// 56
	int protocol2;				// 60
	bool slim;					// 64
	bool transparency;			// 65
	std::string skin;			// 68

	virtual ~LoginPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream *) const;
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const;
};
