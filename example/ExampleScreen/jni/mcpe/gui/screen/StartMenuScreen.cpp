#include "../../../shared.h"
#include "StartMenuScreen.h"
#include "ExampleScreen.h"
#include "../element/TButton.h"
#include "../element/ImageWithBackground.h"
#include "../../MinecraftClient.h"

// static 초기화
Touch::StartMenuScreen::InitReal Touch::StartMenuScreen::init_real = NULL;
Touch::StartMenuScreen::SetupPositionsReal Touch::StartMenuScreen::setupPositions_real = NULL;
Touch::StartMenuScreen::ButtonClickedReal Touch::StartMenuScreen::buttonClicked_real = NULL;
Touch::TButton *Touch::StartMenuScreen::_exScreenButton = NULL;

// init함수를 hook한 함수.
void Touch::StartMenuScreen::init_hook(Touch::StartMenuScreen *screen) {
	// _exScreenButton객체가 초기화 안되있을때.
	if(!_exScreenButton) {
		_exScreenButton = new Touch::TButton(0, "Example Screen", NULL, false);
		_exScreenButton->init(screen->_minecraftClient);
	}

	// 버튼 추가.
	screen->_vecBtn.emplace_back(_exScreenButton);

	// 실제 init를 호출.
	Touch::StartMenuScreen::init_real(screen);
}

// setupPositions함수를 hook한 함수.
void Touch::StartMenuScreen::setupPositions_hook(Touch::StartMenuScreen *screen) {
	// 실제 setupPositions를 호출.
	Touch::StartMenuScreen::setupPositions_real(screen);

	// 옵션 버튼을 가져옵니다.
	ImageWithBackground *optionButton = screen->_optionButton;

	// 버튼을 옵션 버튼 위에 놓는다.
	_exScreenButton->_x = optionButton->_x;
	_exScreenButton->_y = optionButton->_y - optionButton->_height - 10;
	_exScreenButton->_width = optionButton->_width;
	_exScreenButton->_height = optionButton->_height;
}

// buttonClicked함수를 hook한 함수.
void Touch::StartMenuScreen::buttonClicked_hook(Touch::StartMenuScreen *screen, Button *button) {
	// 실제 buttonClicked를 호출.
	Touch::StartMenuScreen::buttonClicked_real(screen, button);

	// 클릭한 버튼 id가 추가한 버튼 id라면
	if(button->_buttonId == _exScreenButton->_buttonId) {
		// ExampleScreen으로 스크린을 정한다.
		screen->_minecraftClient->setScreen(new ExampleScreen());
	}
}
