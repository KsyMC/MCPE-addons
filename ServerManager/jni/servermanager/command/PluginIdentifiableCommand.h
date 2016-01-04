#pragma once

class Plugin;

class PluginIdentifiableCommand
{
public:
	virtual ~PluginIdentifiableCommand() {};

	virtual Plugin *getPlugin() const = 0;
};
