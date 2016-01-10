#pragma once

#include <string>
#include <raknet/RakPeer.h>

class RakNetInstance
{
public:
	RakNet::RakPeer *getPeer();
	void _startupIfNeeded(unsigned short, int);
	void host(const std::string &, int, int);
	void announceServer(const std::string &);
};
