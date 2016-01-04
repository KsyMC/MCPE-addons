#pragma once

#include <vector>
#include <string>

class Level;
class SMPlayer;

class SMLevel
{
private:
	Level *level;
	std::vector<SMPlayer *> players;

public:
	SMLevel(Level *level);
	~SMLevel();

	std::vector<SMPlayer *> &getPlayers();
	SMPlayer *getPlayer(const std::string &name) const;
	std::vector<SMPlayer *> matchPlayer(const std::string &partialName) const;
	SMPlayer *getPlayerExact(const std::string &name) const;

	void addPlayer(SMPlayer *player);
	void removePlayer(SMPlayer *player);

	Level *getHandle() const;
};
