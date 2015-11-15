#pragma once

#include <memory>
#include <functional>
#include "CreateWorldScreenType.h"

class Screen;
class SkinPack;

// Size : 20
class ScreenChooser
{
public:
	MinecraftClient *mc;

public:
	ScreenChooser(MinecraftClient &, bool, bool);
	~ScreenChooser();
	void SetCanInvite(bool);
	void _pushScreen(std::shared_ptr<BaseScreen>, bool);
	void _pushScreen(std::shared_ptr<BaseScreen>, std::unique_ptr<AbstractScreenSetupCleanupStrategy>, bool);
	void enableNewScreens(bool);
	void getInBedScreen(void);
	void isNewScreensEnabled(void);
	void popScreen(AbstractScreen &, int);
	void pushAddExternalServerScreen(void);
	void pushAnvilScreen(Player &, BlockPos const &);
	void pushBlockSelectionScreen(void);
	void pushBrewingStandScreen(Player &, BlockPos const &);
	void pushChatScreen(void);
	void pushChestScreen(Player &, BlockPos const &);
	void pushConsoleScreen(void);
	void pushCreateWorldScreen(CreateWorldScreenType);
	void pushCreateWorldScreen(LevelSummary const &);
	void pushDeathScreen(void);
	void pushDeleteWorldScreen(LevelSummary const &);
	void pushEnchantingScreen(Player &, BlockPos const &);
	void pushFurnaceScreen(Player &, BlockPos const &);
	void pushGamePadLayoutScreen(bool);
	void pushGameViewerScreen(void);
	void pushHudScreen(void);
	void pushInBedScreen(void);
	void pushKeyboardLayoutScreen(bool);
	void pushLanguageScreen(void);
	void pushLocalPlayScreen(bool, bool);
	void pushMakeInfiniteScreen(LevelSummary const &, StorageVersion);
	void pushMessageBoxScreen(std::string const &);
	void pushMobEffectsScreen(void);
	void pushOptionsScreen(bool, bool, std::string const &);
	void pushPausePrevScreen(void);
	void pushPauseScreen(void);
	void pushPlaySpaceScreen(void);
	void pushProgressScreen(bool, std::function<void (void)>);
	void pushRealityScreen(void);
	void pushRemotePlayScreen(void);
	void pushSelectSkinTypeScreen(bool, bool, std::string const &);
	void pushShowSkinPackScreen(SkinPack const &, std::string const &, bool);
	void pushSkinsScreen(void);
	void pushSurvivalInventoryScreen(SurvivalInventoryScreen::CraftingType, BlockPos const &);
	void pushTextEditScreen(SignBlockEntity *);
	void pushUpsellScreen(bool);
	void pushXblLoginScreen(void);
	void setDisconnectScreen(std::string const &);
	void setGameplayScreen(void);
	void setStartMenuScreen(void);
};
