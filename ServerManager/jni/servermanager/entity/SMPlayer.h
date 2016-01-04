#pragma once

#include <vector>

#include "servermanager/entity/SMMob.h"
#include "minecraftpe/gamemode/GameType.h"

class SMBlockSource;
class PacketSender;
class Player;
class Vec3;
class Vec2;
class Inventory;
class ItemInstance;

class SMPlayer : public SMMob
{
protected:
	std::string displayName;
	std::string listName;

	SMBlockSource *region;

	std::string ipAddress;

public:
	SMPlayer(Player *entity, const std::string &ipAddress);
	virtual ~SMPlayer();

	virtual void sendMessage(const std::string &message);
	virtual void sendTranslation(const std::string &message, const std::vector<std::string> &params);
	virtual void sendPopup(const std::string &message, const std::string &subtitle = "");
	virtual void sendTip(const std::string &message);

	virtual bool isLocalPlayer() const;

	PacketSender *getPacketSender() const;
	const std::string &getAddress() const;

	std::string getDisplayName() const;
	void setDisplayName(const std::string &name);

	void teleport(SMPlayer *target);
	void teleport(const Vec3 &pos, const Vec2 &rot);

	void setGameType(GameType gametype);
	int getGameType() const;

	std::string getName() const;

	Inventory *getInventory() const;
	ItemInstance *getSelectedItem() const;
	SMBlockSource *getRegion() const;

	Player *getHandle() const;
};
