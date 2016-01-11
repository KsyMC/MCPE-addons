#pragma once

#include <vector>

#include "servermanager/entity/SMMob.h"
#include "minecraftpe/gamemode/GameType.h"

class PacketSender;
class Player;
class Vec3;
class Vec2;
class Inventory;
class ItemInstance;

class SMPlayer : public SMMob
{
public:
	bool joined;

	int lastPacket;
	int lastBlock;

protected:
	std::string displayName;
	std::string listName;

	std::string ipAddress;

public:
	SMPlayer(Server *server, Player *entity);
	~SMPlayer();

	virtual void sendRawMessage(const std::string &message);
	virtual void sendMessage(const std::string &message);
	virtual void sendMessage(const std::vector<std::string> messages);

	virtual void sendTranslation(const std::string &message, const std::vector<std::string> &params);
	virtual void sendPopup(const std::string &message, const std::string &subtitle = "");
	virtual void sendTip(const std::string &message);

	virtual bool isLocalPlayer() const;

	bool isOp() const;
	void setOp(bool value);

	float getEyeHeight() const;
	float getEyeHeight(bool ignoreSneaking) const;

	void setSneaking(bool sneak);
	bool isSneaking() const;

	void setSprinting(bool sprinting);
	bool isSprinting() const;

	PacketSender *getPacketSender() const;

	const std::string &getAddress() const;
	void setAddress(const char *ipAddress);

	std::string getDisplayName() const;
	void setDisplayName(const std::string &name);

	bool teleport(const Location &location, PlayerTeleportEvent::TeleportCause cause = PlayerTeleportEvent::PLUGIN);

	void setGameType(GameType gametype);
	GameType getGameType() const;

	std::string getName() const;

	Inventory *getInventory() const;
	ItemInstance *getSelectedItem() const;

	Player *getHandle() const;
	void setHandle(Player *player);
};
