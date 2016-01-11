#pragma once

#include <string>

class BanEntry
{
private:
	std::string target;
	std::string reason;
	std::string source;

public:
	BanEntry(const std::string &target);

	std::string getTarget() const;

	std::string getSource() const;
	void setSource(const std::string &source);

	std::string getReason() const;
	void setReason(const std::string &reason);

	static BanEntry *fromString(const std::string &str);
	std::string getString() const;
};
