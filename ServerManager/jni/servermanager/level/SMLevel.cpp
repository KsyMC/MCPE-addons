#include "servermanager/level/SMLevel.h"

SMLevel::SMLevel(Server *server, Level *level)
{
	this->server = server;
	this->level = level;
}

SMLevel::~SMLevel()
{
}

Server *SMLevel::getServer() const
{
	return server;
}

Level *SMLevel::getHandle() const
{
	return level;
}
