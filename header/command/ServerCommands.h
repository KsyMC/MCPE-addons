#pragma once

class ServerCommandParser;
class Level;

class ServerCommands
{
public:
	static void setupStandardServer(ServerCommandParser &, Level &);
};
