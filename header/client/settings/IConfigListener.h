#pragma once

class Config;

class IConfigListener
{
public:
	virtual ~IConfigListener();
	virtual void onConfigChanged(Config const &) = 0;
};
