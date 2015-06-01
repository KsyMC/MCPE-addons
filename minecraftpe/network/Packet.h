#pragma once

class NetEventCallback;

namespace RakNet
{
	class BitStream;
	class RakNetGUID;
}

// Size : 16
class Packet
{
public:
	//void **vtable;	// 0
	int wtf1;			// 4
	int wtf2;			// 8
	bool wtf3;			// 12

public:
	Packet();
	virtual ~Packet();
	virtual int getId() const = 0;
	virtual void write(RakNet::BitStream *) const = 0;
	virtual void read(RakNet::BitStream *) = 0;
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *) const = 0;
};