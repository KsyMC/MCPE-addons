#pragma once

#include "shared.h"

class Gui
{
public:
	void displayClientMessage(string const &);
	void displayChatMessage(string const &, string const &);
	void displayLocalizableMessage(string const &, vector<string> const &);
	void showPopupNotice(string const &, string const &);
	void showTipMessage(string const &);
	void displaySystemMessage(string const &);
};
