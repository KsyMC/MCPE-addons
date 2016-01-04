#pragma once

#include <string>
#include <vector>

class SMPlayer;
class CommandMap;

class Command
{
private:
	std::string name;
	std::string nextLabel;
	std::string label;
	std::vector<std::string> aliases;
	std::vector<std::string> activeAliases;
	CommandMap *commandMap;

protected:
	std::string description;
	std::string usageMessage;

	Command(const std::string &name, const std::string &description = "", const std::string &usageMessage = "", const std::vector<std::string> &aliases = {});

public:
	virtual ~Command();

	virtual bool execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args) = 0;

	virtual bool isVanillaCommand() const;
	virtual bool isPluginCommand() const;

	std::string getName() const;

	std::string getDescription() const;
	void setDescription(const std::string &description);

	std::vector<std::string> getAliases() const;
	bool setAliases(const std::vector<std::string> &aliases);

	bool registerCommand(CommandMap *commandMap);
	bool unregister(CommandMap *commandMap);
	bool isRegistered() const;

	bool setLabel(const std::string &name);
	std::string getLabel() const;

	void setUsage(const std::string &usage);
	std::string getUsage() const;

	static void broadcastCommandMessage(SMPlayer *source, const std::string &message, bool sendToSource = true);
	static void broadcastCommandTranslation(SMPlayer *source, const std::string &message, const std::vector<std::string> &params, bool sendToSource = true);

private:
	bool allowChangesFrom(CommandMap *commandMap);
};
