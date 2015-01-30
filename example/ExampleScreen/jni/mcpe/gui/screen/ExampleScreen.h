// 한번만 포함(include) 하기 위함
#ifndef __EXAMPLESCREEN_H__
#define __EXAMPLESCREEN_H__

// Screen을 상속하기 위해서 include
#include "Screen.h"

namespace Touch {
	class TButton;
	class THeader;
}

// Screen을 상속하는 ExampleScreen 스크린.
class ExampleScreen : public Screen {
public:
	// 버튼
	Touch::TButton *_exampleButton;

	// 헤더
	Touch::THeader *_exampleHeader;

public:
	ExampleScreen();
	virtual ~ExampleScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual bool handleBackEvent(bool);
	virtual void buttonClicked(Button *);
	void closeScreen();
};

#endif
