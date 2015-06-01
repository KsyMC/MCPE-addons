#pragma once

#include <deque>
#include "Screen.h"

class ImageWithBackground;

// Size : 244
class ChatScreen : public Screen
{
public:
	static std::deque<std::string> sentMessages;

public:
	std::string _message;				// 200
	char filler1[16];					// 204
	ImageWithBackground *_chatButton;	// 220

public:
	ChatScreen(bool);
	virtual ~ChatScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual bool handleBackEvent(bool);
	virtual void tick();
	virtual void removed();
	virtual bool renderGameBehind();
	virtual bool isPauseScreen();
	virtual bool isErrorScreen();
	virtual bool isInGameScreen();
	virtual void closeOnPlayerHurt();
	virtual void setTextboxText(const std::string &);
	virtual void buttonClicked(Button *);
	virtual void keyPressed(int);
	virtual void keyboardNewChar(const std::string &, bool);
	void sendChatMessage();
	void drawChatMessages(int);
	void guiMessagesUpdated();
	void updateGuiMessages();
	void updateKeyboardVisibility();
	void updateToggleKeyboardButton();
};