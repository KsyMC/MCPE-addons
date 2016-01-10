#pragma once

#include "raknet/BitStream.h"
#include "raknet/RakNetTypes.h"

class NetEventCallback;

class Packet
{
public:
	//void **vtable;	// 0
	int i1;				// 4
	int i2;				// 8
	bool b1;			// 12

	Packet();
	virtual ~Packet();
	virtual int getId() const = 0;
	virtual void write(RakNet::BitStream *) const = 0;
	virtual void read(RakNet::BitStream *) = 0;
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const = 0;
};
