#pragma once

#include <string>
#include "permission/SMServerOperator.h"

class SMPlayer;

class ISMPlayer : public SMServerOperator
{
public:
	virtual bool isOnline() = 0;

	virtual std::string getName() const = 0;

	virtual bool isBanned() const = 0;
	virtual bool isWhitelisted() const = 0;
	virtual bool isOp() const;

	virtual void setBanned(bool banned) = 0;
	virtual void setWhitelisted(bool value) = 0;
	virtual void setOp(bool value);

	virtual SMPlayer *getPlayer() = 0;
};
