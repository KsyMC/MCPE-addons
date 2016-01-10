#pragma once

#include <string>
#include <vector>

class Gui
{
public:
	void displayClientMessage(const std::string &);
	void displayChatMessage(const std::string &, const std::string &);
	void displayLocalizableMessage(const std::string &, const std::vector<std::string> &);
	void showPopupNotice(const std::string &, const std::string &);
	void showTipMessage(const std::string &);
	void displaySystemMessage(const std::string &);
};
