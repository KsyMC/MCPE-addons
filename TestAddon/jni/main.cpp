#include <jni.h>
#include <dlfcn.h>
#include <algorithm>

#include "minecraftpe/util/Vec3.h"
#include "minecraftpe/util/Vec2.h"
#include "minecraftpe/entity/MobFactory.h"
#include "minecraftpe/entity/player/Player.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/level/TileSource.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraftpe/client/gui/StartMenuScreen.h"
#include "minecraftpe/client/gui/TButton.h"
#include "minecraftpe/client/gui/ImageWithBackground.h"
#include "minecraftpe/client/audio/SoundEngine.h"
#include "minecraftpe/item/DoorItem.h"
#include "minecraftpe/item/TileItem.h"
#include "minecraftpe/tile/DoorTile.h"
#include "minecraftpe/tile/material/Material.h"

#include "TestAddon.h"
#include "TestAddon/entity/passive/Horse.h"
#include "TestAddon/client/model/HorseModel.h"
#include "TestAddon/client/model/WingedSteveModel.h"
#include "TestAddon/client/renderer/entity/HorseRenderer.h"
#include "TestAddon/client/gui/TestScreen.h"
#include "TestAddon/tile/AnywhereDoorTile.h"

#include "Substrate.h"
#include "shared.h"
#include "AddonManager.h"
#include "dl_internal.h"
#include "sounds.h"

TestAddon testAddon;
Touch::TButton *screenTestButton;

static Item *Item_anywhereDoorItem;
static Tile *Tile_anywhereDoor;

static void (*Touch$StartMenuScreen$Destructor_real)(Touch::StartMenuScreen *);
static void Touch$StartMenuScreen$Destructor_hook(Touch::StartMenuScreen *_this)
{
	Touch$StartMenuScreen$Destructor_real(_this);

	delete screenTestButton;
	screenTestButton = NULL;
}

static void (*Touch$StartMenuScreen$init_real)(Touch::StartMenuScreen *);
static void Touch$StartMenuScreen$init_hook(Touch::StartMenuScreen *_this)
{
	Touch$StartMenuScreen$init_real(_this);

	if (!screenTestButton)
	{
		screenTestButton = new Touch::TButton(10, "menu.test", NULL, false, 0x7FFFFFFF);
		screenTestButton->init(_this->mc);
	}
	_this->buttonList.push_back(screenTestButton);
}

static void (*Touch$StartMenuScreen$setupPositions_real)(Touch::StartMenuScreen *);
static void Touch$StartMenuScreen$setupPositions_hook(Touch::StartMenuScreen *_this)
{
	Touch$StartMenuScreen$setupPositions_real(_this);

	screenTestButton->xPosition = _this->languageButton->xPosition - screenTestButton->width - 3;
	screenTestButton->yPosition = _this->languageButton->yPosition;
	screenTestButton->height = _this->languageButton->height;
}

static void (*Touch$StartMenuScreen$buttonClicked_real)(Touch::StartMenuScreen *, Button *);
static void Touch$StartMenuScreen$buttonClicked_hook(Touch::StartMenuScreen *_this, Button *button)
{
	switch (button->id)
	{
	case 10:
		_this->mc->setScreen(new TestScreen());
		break;
	default:
		Touch$StartMenuScreen$buttonClicked_real(_this, button);
	}
}

/*static Mob *(*MobFactory$CreateMob_real)(MobFactory *, int, TileSource &, const Vec3 &, Vec2 *);
static Mob *MobFactory$CreateMob_hook(MobFactory *_this, int typeId, TileSource &tileSource, const Vec3 &pos, Vec2 *rotation)
{
	Mob *mob = NULL;

	switch (typeId)
	{
	case 100: case 5988: case 12:
		mob = new Horse(tileSource);
		break;
	default:
		return MobFactory$CreateMob_real(_this, typeId, tileSource, pos, rotation);
	}
	mob->postInit();

	Vec2 vec2;
	if (rotation == NULL)
	{
		vec2.x = 0;
		vec2.y = 0;

		Level *level = tileSource.getLevel();
		LOGI("%d", level->random.genrand_int32());
	}
	else
	{
		vec2.x = rotation->x;
		vec2.y = rotation->y;
	}
	mob->moveTo(pos, vec2);

	return mob;
}*/

static void (*EntityRenderDispatcher$EntityRenderDispatcher_real)(EntityRenderDispatcher *);
static void EntityRenderDispatcher$EntityRenderDispatcher_hook(EntityRenderDispatcher *_this)
{
	EntityRenderDispatcher$EntityRenderDispatcher_real(_this);
	_this->entityRenderers[8] = new HorseRenderer(new HorseModel(), 0);
	_this->entityRenderers[14] = new HorseRenderer(new WingedSteveModel(), 0);
}

static void (*SoundEngine$init_real)(SoundEngine *, Minecraft *, Options *);
static void SoundEngine$init_hook(SoundEngine *_this, Minecraft *mc, Options *options)
{
	//_this->repository.add("mob.horsehurt", );
	SoundEngine$init_real(_this, mc, options);
}

static void (*SoundRepository$add_real)(SoundRepository *, const std::string &, SoundDesc &);
static void SoundRepository$add_hook(SoundRepository *_this, const std::string &sndName, SoundDesc &desc)
{
	LOGI("Sound type : %s, Size : %d, Speed(x) : %d, Format : %d , Sample Rate : %d", sndName.c_str(), desc.size, desc.speed, desc.format, desc.sampleRate);

	if (!sndName.compare("random.hurt"))
	{
		desc.size = 60673;
		desc.pcm = PCM_custom_hurt;
	}
	else if (!sndName.compare("random.click"))
		desc.speed = 1;

	SoundRepository$add_real(_this, sndName, desc);
}

static void(*Item$initItems_real)();
static void Item$initItems_hook()
{
	DoorItem *anywhereDoorItem = new DoorItem(204, Material::stone);
	anywhereDoorItem->setIcon("door_wood", 0);
	anywhereDoorItem->setCategory(2);
	anywhereDoorItem->setNameID("anywhereDoor");

	Item_anywhereDoorItem = anywhereDoorItem;

	Item$initItems_real();
}

static void(*Item$initCreativeItems_real)();
static void Item$initCreativeItems_hook()
{
	Item$initCreativeItems_real();

	Item::addCreativeItem(Item_anywhereDoorItem, 0);
	Item::addCreativeItem(Item::mobPlacer, 41);
}

static void(*Tile$initTiles_real)();
static void Tile$initTiles_hook()
{
	Tile$initTiles_real();

	AnywhereDoorTile *anywhereDoor = new AnywhereDoorTile(188, Material::stone);
	anywhereDoor->init();
	anywhereDoor->setDestroyTime(3.0f);
	anywhereDoor->setSoundType(Tile::SOUND_GLASS);
	anywhereDoor->setCategory(2);
	anywhereDoor->setNameId("anywhereDoor");

	Tile_anywhereDoor = anywhereDoor;

	for (int i = 0, j = -256; i < 256; i++, j++) {
		Tile *tile = Tile::tiles[i];
		if (tile && !Item::items[i]) {
			TileItem *tileItem = new TileItem(j);
			tileItem->setCategory(tile->category);
		}
	}
}

static bool(*DoorItem$useOn_real)(DoorItem *, ItemInstance *, Player *, int, int, int, signed char, float, float, float);
static bool DoorItem$useOn_hook(DoorItem *_this, ItemInstance *itemInstance, Player *player, int x, int y, int z, signed char side, float bx, float by, float bz)
{
	if (_this->doorMaterial == Material::stone)
	{
		TileSource *tileSource = player->tileSource;
		if (Tile_anywhereDoor->mayPlace(tileSource, x, y + 1, z))
		{
			DoorItem::place(tileSource, x, y + 1, z, 0, Tile_anywhereDoor);
			return true;
		}
		else
			return false;
	}
	return DoorItem$useOn_real(_this, itemInstance, player, x, y, z, side, bx, by, bz);
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	soinfo2 *handle = (soinfo2 *) dlopen("libminecraftpe.so", RTLD_LAZY);
	void *Touch$StartMenuScreen$Destructor = dlsym(handle, "_ZN5Touch15StartMenuScreenD2Ev");
	void *EntityRenderDispatcher$EntityRenderDispatcher = dlsym(handle, "_ZN22EntityRenderDispatcherC2ER15MinecraftClient");
	void *SoundEngine$init = dlsym(handle, "_ZN11SoundEngine4initEP9MinecraftP7Options");

	MSHookFunction(Touch$StartMenuScreen$Destructor, (void *)&Touch$StartMenuScreen$Destructor_hook, (void **)&Touch$StartMenuScreen$Destructor_real);
	MSHookFunction((void *)&Touch::StartMenuScreen::init, (void *)&Touch$StartMenuScreen$init_hook, (void **)&Touch$StartMenuScreen$init_real);
	MSHookFunction((void *)&Touch::StartMenuScreen::setupPositions, (void *)&Touch$StartMenuScreen$setupPositions_hook, (void **)&Touch$StartMenuScreen$setupPositions_real);
	MSHookFunction((void *)&Touch::StartMenuScreen::buttonClicked, (void *)&Touch$StartMenuScreen$buttonClicked_hook, (void **)&Touch$StartMenuScreen$buttonClicked_real);
	//MSHookFunction((void *)&MobFactory::CreateMob, (void *)&MobFactory$CreateMob_hook, (void **)&MobFactory$CreateMob_real);
	MSHookFunction(EntityRenderDispatcher$EntityRenderDispatcher, (void *)&EntityRenderDispatcher$EntityRenderDispatcher_hook, (void **)&EntityRenderDispatcher$EntityRenderDispatcher_real);
	MSHookFunction((void *)&SoundEngine::init, (void *)&SoundEngine$init_hook, (void **)&SoundEngine$init_real);
	MSHookFunction((void *)&SoundRepository::add, (void *)&SoundRepository$add_hook, (void **)&SoundRepository$add_real);
	MSHookFunction((void *)&Item::initItems, (void *)&Item$initItems_hook, (void **)&Item$initItems_real);
	MSHookFunction((void *)&Item::initCreativeItems, (void *)&Item$initCreativeItems_hook, (void **)&Item$initCreativeItems_real);
	MSHookFunction((void *)&Tile::initTiles, (void *)&Tile$initTiles_hook, (void **)&Tile$initTiles_real);
	MSHookFunction((void *)&DoorItem::useOn, (void *)&DoorItem$useOn_hook, (void **)&DoorItem$useOn_real);

	AddonManager::registerAddon(&testAddon);

	return JNI_VERSION_1_2;
}
