#pragma once

#include <string>
#include <vector>
#include "../event/TextContainer.h"

class CommandMap;
class SMPlayer;

class Command
{
public:
	static int MAX_COORD;
	static int MIN_COORD;

private:
	CommandMap *commandMap;

	std::string name;
	std::string label;

	std::vector<std::string> aliases;
	std::vector<std::string> activeAliases;

protected:
	std::string description;
	std::string usageMessage;

public:
	Command(std::string const &name, std::string const &description = "", std::string const &usageMessage = "", std::vector<std::string> const &aliases = {});
	virtual ~Command();

	virtual bool execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args) = 0;

	std::string getName() const;
	std::string getDescription() const;
	std::vector<std::string> getAliases() const;
	void setAliases(std::vector<std::string> const &);

	void registerCommand(CommandMap *);
	bool isRegistered() const;

	void setLabel(std::string const &label);
	std::string getLabel() const;

	void setUsage(std::string const &usage);
	std::string getUsage() const;

	static std::string implode(std::vector<std::string> const &v, std::string const &c);
	static void broadcastCommandMessage(SMPlayer *source, TextContainer const &message, bool sendToSource = true);

protected:
	int getInteger(SMPlayer *sender, std::string const &value, int min = MIN_COORD, int max = MAX_COORD) const;
};
