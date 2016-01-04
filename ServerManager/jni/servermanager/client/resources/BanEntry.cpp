#include "servermanager/client/resources/BanEntry.h"
#include "servermanager/util/SMUtil.h"

BanEntry::BanEntry(const std::string &target)
{
	this->target = target;
	this->reason = "Generic reason";
	this->source = "Unknown";
}

std::string BanEntry::getTarget() const
{
	return target;
}

std::string BanEntry::getSource() const
{
	return source;
}

void BanEntry::setSource(const std::string &source)
{
	this->source = source;
}

std::string BanEntry::getReason() const
{
	return reason;
}

void BanEntry::setReason(const std::string &reason)
{
	this->reason = reason;
}

BanEntry *BanEntry::fromString(const std::string &str)
{
	if(str.length() < 2)
		return NULL;

	std::vector<std::string> strs = SMUtil::split(SMUtil::trim(str), '|');

	BanEntry *entry = new BanEntry(SMUtil::trim(strs[0]));
	if(strs.size() >= 3)
	{
		entry->setSource(SMUtil::trim(strs[1]));
		entry->setReason(SMUtil::trim(strs[2]));
	}
	return entry;
}

std::string BanEntry::getString() const
{
	return getTarget() + "|" + getSource() + "|" + getReason();
}
