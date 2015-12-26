#pragma once

#include "shared.h"

class RakNetInstance
{
public:
	RakNet::RakPeer *getPeer();
	void _startupIfNeeded(unsigned short, int);
	void host(string const &, int, int);
	void announceServer(string const &);
};
