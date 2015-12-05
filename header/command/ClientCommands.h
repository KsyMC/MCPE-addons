#pragma once

class ServerCommandParser;
class Options;
class LocalPlayer;
class TextureGroup;
class LevelArchiver;
class GameMode;

class ClientCommands
{
public:
	static void setupDebug(ServerCommandParser &, Options &);
	static void setupStandard(ServerCommandParser &, LocalPlayer &, TextureGroup &, LevelArchiver &, GameMode &);
	static void setupProfiling(ServerCommandParser &, Options &);
};
