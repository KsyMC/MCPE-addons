#pragma once

#include <vector>
#include <string>

class Server;
class Level;

class SMLevel
{
private:
	Server *server;
	Level *level;

public:
	SMLevel(Server *server, Level *level);
	~SMLevel();

	Server *getServer() const;

	Level *getHandle() const;
};
