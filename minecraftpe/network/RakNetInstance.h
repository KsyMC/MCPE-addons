#pragma once

#include "IRakNetInstance.h"

// Size : 72
class RakNetInstance : public IRakNetInstance
{
public:
	//void **vtable;			// 0
	RakNet::RakPeer *_RakPeer;	// 4
	char filler1[64];			// 8

public:
	RakNetInstance();
	virtual ~RakNetInstance();
	virtual void host(const std::string &, int, int);
	virtual void connect(char const *, int);
	virtual void setIsLoggedIn(bool);
	virtual void startPingForHosts(int);
	virtual void startPingForHosts(int, const std::vector<std::string> &);
	virtual void stopPingForHosts();
	virtual void getServerList();
	virtual void clearServerList();
	virtual void disconnect();
	virtual void announceServer(const std::string &);
	virtual RakNet::RakPeer *getPeer();
	virtual void isMyLocalGuid(RakNet::RakNetGUID const &);
	virtual void runEvents(NetEventCallback *);
	virtual void send(Packet &);
	virtual void send(const RakNet::RakNetGUID  &, Packet &);
	virtual void send(Packet *);
	virtual void send(const RakNet::RakNetGUID &, Packet *);
	virtual void send(const RakNet::AddressOrGUID &, Packet &, bool);
	virtual void isServer();
	virtual void isProbablyBroken();
	virtual void resetIsBroken();
	virtual void getStatistics(RakNet::RakNetStatistics *);
	virtual void getPacketCounts();
};