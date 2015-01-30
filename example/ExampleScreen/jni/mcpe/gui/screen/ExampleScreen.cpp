#include "../../../shared.h"
#include "ExampleScreen.h"
#include "StartMenuScreen.h"
#include "../../MinecraftClient.h"
#include "../element/TButton.h"
#include "../element/THeader.h"

// 생성자 부분.
ExampleScreen::ExampleScreen() {
	// 포인터를 초기화 해야겠죠?
	_exampleButton = NULL;
	_exampleHeader = NULL;
}

// 제거자 부분.
ExampleScreen::~ExampleScreen() {
	delete _exampleButton; // 스크린 제거시 버튼도 같이 제거!
	delete _exampleHeader; // 스크린 제거시 헤더도 같이 제거!
}

// 렌더 부분입니다. 인자 i1, i2, f1 은 알 수가 없음!
// 찾았다면 바로 말해주세요.
void ExampleScreen::render(int i1, int i2, float f1) {
	// 뒷배경에 파노라마 렌더링!
	renderMenuBackground(f1);

	// 글자를 렌더! "String"을 표시하고, 좌표 10, 100 에 드로우(Draw) 해줍니다. 색은 White(흰색).
	_screenRenderer.drawString(_minecraftClient->_font, "String", 10, 100, Color::WHITE);

	// 버튼 등등을 렌더링합니다.
	Screen::render(i1, i2, f1);
}

// 버튼 등등 초기화 부분
void ExampleScreen::init() {
	// 버튼을 생성합니다. 버튼 id는 0이고, 이름은 "Button" 이며, MinecraftClient는 NULL, init false.
	// 추후에 따로 init 해줍니다. (이유는 모름)
	_exampleButton = new Touch::TButton(0, "Button", NULL, false);

	// 헤더를 생성합니다. 첫번째 인자는 모르겠어요.. 나타나는 헤더는 "Header" 입니다.
	_exampleHeader = new Touch::THeader(0, "Header");

	// 추후에 init 해줍니다.
	_exampleButton->init(_minecraftClient);

	// 스크린에 버튼 등등을 추가해줍니다.
	_vecBtn.push_back(_exampleButton);

	// Label 등은 Gui2E에 넣어줍니다.
	_vecGui2E.push_back(_exampleHeader);
}

// 버튼 등등 위치 정하는 부분
void ExampleScreen::setupPositions() {
	// 헤더는 폰의 가로 크기만큼 !
	_exampleHeader->_width = _width;

	// x좌표는 10!
	_exampleButton->_x = 10;

	// y좌표는 헤더 높이 + 10
	_exampleButton->_y = _exampleHeader->_height + 10;
}

// 뒤로가기 버튼을 눌렀을때 부분
bool ExampleScreen::handleBackEvent(bool b1) {
	if(!b1) {
		// 화면을 닫습니다.
		closeScreen();
	}

	return true;
}

// 버튼 클릭시 처리부분.
void ExampleScreen::buttonClicked(Button *button) {
	// 클릭한 버튼이 추가한 버튼의 아이디와 같다면
	if(button->_buttonId == _exampleButton->_buttonId) {
		// 화면을 닫습니다.
		closeScreen();
	}
}

// 화면 닫기 함수. 직접 만든 함수입니다.
void ExampleScreen::closeScreen() {
	// 스크린을 처음 스크린으로 정합니다.
	_minecraftClient->setScreen(new Touch::StartMenuScreen());
}
