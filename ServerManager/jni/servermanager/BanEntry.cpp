#include "servermanager/BanEntry.h"
#include "servermanager/util/SMUtil.h"

BanEntry::BanEntry(const std::string &target)
{
	this->target = target;
	this->reason = "(Unknown)";
	this->source = "Banned by an operator.";
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

	strs.erase(strs.begin());
	if(strs.size() > 0)
	{
		entry->setSource(SMUtil::trim(strs[0]));

		strs.erase(strs.begin());
		if(strs.size() > 0)
		{
			entry->setReason(SMUtil::trim(strs[0]));
		}
	}
	return entry;
}

std::string BanEntry::getString() const
{
	return getTarget() + "|" + getSource() + "|" + getReason();
}
