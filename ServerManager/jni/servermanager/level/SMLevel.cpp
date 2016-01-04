#include <algorithm>

#include "servermanager/level/SMLevel.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/util/SMUtil.h"

SMLevel::SMLevel(Level *level)
{
	this->level = level;
}

SMLevel::~SMLevel()
{
	for(SMPlayer *player : players)
		delete player;

	players.clear();
}

std::vector<SMPlayer *> &SMLevel::getPlayers()
{
	return players;
}

SMPlayer *SMLevel::getPlayer(const std::string &name) const
{
	SMPlayer *found = NULL;
	std::string lowerName = SMUtil::toLower(name);
	int delta = 2147483647;

	for(SMPlayer *player : players)
	{
		std::string n = SMUtil::toLower(player->getName());
		if(n.find(lowerName) != std::string::npos)
		{
			int curDelta = n.length() - lowerName.length();
			if(curDelta < delta)
			{
				found = player;
				delta = curDelta;
			}

			if(curDelta == 0)
				break;
		}
	}
	return found;
}

std::vector<SMPlayer *> SMLevel::matchPlayer(const std::string &partialName) const
{
	std::string lname = SMUtil::toLower(partialName);
	std::vector<SMPlayer *> matchedPlayers;

	for(auto iterPlayer : players)
	{
		std::string iterPlayerName = iterPlayer->getName();
		if(!iterPlayerName.compare(lname))
		{
			matchedPlayers.clear();
			matchedPlayers.push_back(iterPlayer);

			break;
		}
		else if(iterPlayerName.find(lname))
			matchedPlayers.push_back(iterPlayer);
	}
	return matchedPlayers;
}

SMPlayer *SMLevel::getPlayerExact(const std::string &name) const
{
	std::string lname = SMUtil::toLower(name);

	for(SMPlayer *player : players)
	{
		if(!SMUtil::toLower(player->getName()).compare(lname))
			return player;
	}
	return NULL;
}

void SMLevel::addPlayer(SMPlayer *player)
{
	players.push_back(player);
}

void SMLevel::removePlayer(SMPlayer *player)
{
	players.erase(std::find(players.begin(), players.end(), player));
	delete player;
}

Level *SMLevel::getHandle() const
{
	return level;
}
