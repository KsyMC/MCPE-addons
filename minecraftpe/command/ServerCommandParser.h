#pragma once

#include <string>
#include <vector>
#include <functional>
#include "../util/Token.h"

class Minecraft;
class GuiMessage;
class Player;

class ServerCommandParser
{
public:
	class Command
	{
	public:
		Command(const std::function<std::string (const std::vector<Token> &)> &, const std::string &);
		void checkParameters(const std::vector<Token> &);
	};

public:
	ServerCommandParser(Minecraft *);
	std::string _give(Minecraft *, const std::string &, const Token &, int, int);
	std::string _playerFlag(Minecraft *, const std::string &, const std::string &, bool);
	std::string result(const std::string &);
	void addCommand(const std::string &, const std::string &, const std::function<std::string (const std::vector<Token> &)> &);
	void executeCommand(const GuiMessage &);
};
