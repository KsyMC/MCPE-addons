#pragma once

#include <string>
#include <vector>

#include "ISMPlayer.h"
#include "raknet/RakNetTypes.h"
#include "event/TextContainer.h"

class ServerManager;
class SMLevel;
class Player;
class Packet;
class PacketSender;
class Inventory;
class BlockSource;

class SMPlayer : public ISMPlayer
{
public:
	bool loggedIn;

	bool spawned;

	SMLevel *level;

protected:
	Player *realPlayer;

	int messageCounter;

	bool connected;

	ServerManager *server;

	PacketSender *packetSender;

	RakNet::RakNetGUID guid;

	std::string ip;
	unsigned short port;

	std::string username;
	std::string displayName;
	std::string iusername;

public:
	SMPlayer(ServerManager *server, PacketSender *packetSender, RakNet::RakNetGUID const &guid, std::string const &ip, unsigned short port);
	virtual ~SMPlayer();

	TextContainer getLeaveMessage() const;

	bool isConnected() const;

	virtual bool isOnline();

	virtual std::string getName() const;
	std::string getDisplayName() const;

	virtual bool isBanned() const;
	virtual bool isWhitelisted() const;
	virtual bool isOp() const;

	virtual void setBanned(bool value);
	virtual void setWhitelisted(bool value);
	virtual void setOp(bool value);

	std::string getAddress() const;
	unsigned short getPort() const;

	bool dataPacket(Packet const &packet);

	int getGamemode() const;
	void setGamemode(int mode);
	bool isSurvival() const;
	bool isCreative() const;

	virtual SMPlayer *getPlayer();

	virtual bool isLocalPlayer() const;

	void setLevel(SMLevel *level);
	SMLevel *getLevel() const;

	Inventory *getInventory() const;

	BlockSource *getBlockSource() const;

	void save();

	virtual void sendMessage(TextContainer const &message);
	virtual void sendTranslation(std::string const &message, std::vector<std::string> const &parameters);
	virtual void sendPopup(std::string const &message, std::string const &subtitle = "");
	virtual void sendTip(std::string const &message);

	virtual void kick(std::string const &reason, bool isAdmin = true);
	virtual void close(TextContainer const &message, std::string const &reason = "generic reason", bool notify = true);

	void handleDataPacket(Packet *packet);

	virtual void onUpdate();

	ServerManager *getServer() const;

	Player *get() const;
};
