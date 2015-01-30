#include "shared.h"
#include "mcpe/gui/screen/StartMenuScreen.h"
#include "mcpelauncher.h"

void exampleScreen() {
	LOGI("제발 뜨라고 ㅣㅁ럼나돋ㅁ환놔ㅣㄴㅇ하;논ㄷㅁㅇㅇ홍혿ㄴㅅㅈ거자");

	// 버튼을 추가하기 위해 init, setupPositions, buttonClicked 세개를 Hook 합니다.
	mcpelauncher_hook((void *) &Touch::StartMenuScreen::init,					(void *) &Touch::StartMenuScreen::init_hook,					(void **) &Touch::StartMenuScreen::init_real);
	mcpelauncher_hook((void *) &Touch::StartMenuScreen::setupPositions,	(void *) &Touch::StartMenuScreen::setupPositions_hook,		(void **) &Touch::StartMenuScreen::setupPositions_real);
	mcpelauncher_hook((void *) &Touch::StartMenuScreen::buttonClicked,	(void *) &Touch::StartMenuScreen::buttonClicked_hook,		(void **) &Touch::StartMenuScreen::buttonClicked_real);
}
