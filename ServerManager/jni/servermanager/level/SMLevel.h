#pragma once

class SMPlayer;
class Vec3;
class ServerManager;
class Level;
class ItemInstance;

class SMLevel
{
private:
	Level *realLevel;

	ServerManager *server;

public:
	SMLevel(ServerManager *server, Level *level);

	void dropItem(SMPlayer *player, Vec3 const &source, ItemInstance const &item, int delay);

	Level *get() const;
};
