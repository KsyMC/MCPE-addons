#pragma once

#include <string>
#include <memory>
#include "../tileentity/TileEntityType.h"
#include "../client/renderer/texture/TextureUVCoordinateSet.h"
#include "../client/renderer/texture/TextureAtlasTextureItem.h"
#include "../util/TileID.h"
#include "../util/AABB.h"
#include "../util/Brightness.h"

class TextureAtlas;
class Material;
class TileSource;
class Random;
class Player;
class TilePos;
class Entity;
class Vec3;
class Mob;
class ItemInstance;
class FullTile;
typedef int TileType;

// Size : 140
class Tile
{
public:
	// Size : 12
	class SoundType
	{
	public:
		float volume;			// 0
		float frequency;		// 4
		std::string	soundName;	// 8

	public:
		SoundType(const std::string &, float, float);
		~SoundType();
	};

public:
	static Tile *activatorRail;
	static Tile *bed;
	static Tile *beetroot;
	static Tile *bookshelf;
	static Tile *brownMushroom;
	static Tile *brownMushroomBlock;
	static Tile *cactus;
	static Tile *cake;
	static Tile *calmLava;
	static Tile *calmWater;
	static Tile *carrots;
	static Tile *clay;
	static Tile *chest;
	static Tile *cloth;
	static Tile *coalBlock;
	static Tile *coalOre;
	static Tile *cobbleWall;
	static Tile *cocoa;
	static Tile *crops;
	static Tile *deadBush;
	static Tile *diamondBlock;
	static Tile *diamondOre;
	static Tile *dirt;
	static Tile *door_iron;
	static Tile *door_wood;
	static Tile *doublePlant;
	static Tile *emeraldBlock;
	static Tile *emeraldOre;
	static Tile *endPortalFrame;
	static Tile *endStone;
	static Tile *farmland;
	static Tile *fence;
	static Tile *fenceGateAcacia;
	static Tile *fenceGateBigOak;
	static Tile *fenceGateBirch;
	static Tile *fenceGateJungle;
	static Tile *fenceGateOak;
	static Tile *fenceGateSpruce;
	static Tile *fire;
	static Tile *furnace;
	static Tile *furnace_lit;
	static Tile *glass;
	static Tile *glowingObsidian;
	static Tile *goldBlock;
	static Tile *goldOre;
	static Tile *goldenRail;
	static Tile *grass;
	static Tile *grassPathBlock;
	static Tile *gravel;
	static Tile *hardenedClay;
	static Tile *hayBlock;
	static Tile *ice;
	static Tile *info_reserved6;
	static Tile *info_updateGame1;
	static Tile *info_updateGame2;
	static Tile *invisible_bedrock;
	static Tile *ironBlock;
	static Tile *ironFence;
	static Tile *ironOre;
	static Tile *ladder;
	static Tile *lapisBlock;
	static Tile *lapisOre;
	static Tile *lava;
	static Tile *leaves;
	static Tile *leaves2;
	static Tile *lightGem;
	static Tile *litPumpkin;
	static Tile *log;
	static Tile *log2;
	static Tile *melon;
	static Tile *melonStem;
	static Tile *mobSpawner;
	static Tile *monsterStoneEgg;
	static Tile *mossStone;
	static Tile *mycelium;
	static Tile *netherBrick;
	static Tile *netherFence;
	static Tile *netherReactor;
	static Tile *netherrack;
	static Tile *obsidian;
	static Tile *packedIce;
	static Tile *podzol;
	static Tile *potatoes;
	static Tile *pumpkin;
	static Tile *pumpkinStem;
	static Tile *quartzBlock;
	static Tile *rail;
	static Tile *redBrick;
	static Tile *redFlower;
	static Tile *redMushroom;
	static Tile *redMushroomBlock;
	static Tile *redStoneDust;
	static Tile *redStoneOre;
	static Tile *redStoneOre_lit;
	static Tile *redstoneBlock;
	static Tile *reeds;
	static Tile *rock;
	static Tile *sand;
	static Tile *sandStone;
	static Tile *sapling;
	static Tile *sign;
	static Tile *snow;
	static Tile *sponge;
	static Tile *stainedClay;
	static Tile *stairs_brick;
	static Tile *stairs_netherBricks;
	static Tile *stairs_quartz;
	static Tile *stairs_sandStone;
	static Tile *stairs_stone;
	static Tile *stairs_stoneBrickSmooth;
	static Tile *stairs_wood;
	static Tile *stoneBrick;
	static Tile *stoneBrickSmooth;
	static Tile *stoneSlab;
	static Tile *stoneSlabHalf;
	static Tile *stonecutterBench;
	static Tile *tallgrass;
	static Tile *thinGlass;
	static Tile *tnt;
	static Tile *topSnow;
	static Tile *torch;
	static Tile *trapdoor;
	static Tile *unbreakable;
	static Tile *vine;
	static Tile *wallSign;
	static Tile *water;
	static Tile *waterlily;
	static Tile *web;
	static Tile *wood;
	static Tile *woodSlab;
	static Tile *woodSlabHalf;
	static Tile *woodStairsAcacia;
	static Tile *woodStairsBigOak;
	static Tile *woodStairsBirch;
	static Tile *woodStairsDark;
	static Tile *woodStairsJungle;
	static Tile *woolCarpet;
	static Tile *workBench;
	static Tile *yellowFlower;

public:
	static SoundType SOUND_SILENT;
	static SoundType SOUND_SAND;
	static SoundType SOUND_CLOTH;
	static SoundType SOUND_GLASS;
	static SoundType SOUND_METAL;
	static SoundType SOUND_STONE;
	static SoundType SOUND_GRASS;
	static SoundType SOUND_GRAVEL;
	static SoundType SOUND_WOOD;
	static SoundType SOUND_NORMAL;

public:
	static bool shouldTick[255];
	static float translucency[255];
	static bool solid[255];
	static float lightEmission[255];
	static Brightness lightBlock[255];
	static Tile *tiles[255];

public:
	static TextureAtlas *_terrainTextureAtlas;
	static const char *TILE_DESCRIPTION_PREFIX;

public:
	//void **vtable;					// 0
	char filler1[4];					// 4
	AABB aabb;							// 8
	TextureUVCoordinateSet blockIcon;	// 36
	TileID id;							// 68
	Tile::SoundType	stepSound;			// 72
	int blockRendererId;				// 84
	char filler2[20];					// 88
	Material *blockMaterial;			// 108
	char filler3[4];					// 112
	float blockHardness;				// 116
	float blockResistance;				// 120
	int category;						// 124
	char filler4[8];					// 128
	std::string unlocalizedName;		// 136

public:
	Tile(int, const Material *);
	Tile(int, TextureUVCoordinateSet, const Material *);
	Tile(int, std::string, const Material *);
	virtual ~Tile();
	virtual void onFertilized(TileSource *, int, int, int);
	virtual AABB *getShape(TileSource *, int, int, int, AABB &, bool);
	virtual void getShape(unsigned char, AABB &, bool);
	virtual bool isObstructingChests(TileSource *, int, int, int);
	virtual void shouldRenderFace(TileSource *, int, int, int, signed char, const AABB &) const;
	virtual TextureUVCoordinateSet getTexture(signed char);
	virtual TextureUVCoordinateSet getTexture(signed char, int);
	virtual TextureUVCoordinateSet getTexture(TileSource *, int, int, int, signed char);
	virtual void getTessellatedUVs();
	virtual void getCarriedTexture(signed char, int);
	virtual void getAABB(TileSource *, int, int, int, AABB &, int, bool, int);
	virtual void addAABBs(TileSource *, int, int, int, const AABB *, std::vector<AABB> &);
	virtual bool isPathfindable(TileSource *, int, int, int);
	virtual void mayPick();
	virtual bool mayPick(int, bool);
	virtual bool mayPlace(TileSource *, int, int, int, signed char);
	virtual bool mayPlace(TileSource *, int, int, int);
	virtual int getTickDelay();
	virtual void tick(TileSource *, int, int, int, Random *);
	virtual void animateTick(TileSource *, int, int, int, Random *);
	virtual void destroy(TileSource *, int, int, int, int);
	virtual void playerWillDestroy(Player *, int, int, int, int);
	virtual void neighborChanged(TileSource *, int, int, int, int, int, int);
	virtual void onPlace(TileSource *, int, int, int);
	virtual void onRemove(TileSource *, int, int, int);
	virtual TilePos *getSecondPart(TileSource &, const TilePos &, TilePos &);
	virtual void onGraphicsModeChanged(bool, bool);
	virtual int getResource(int, Random *);
	virtual int getResourceCount(Random *);
	virtual float getDestroyProgress(Player *);
	virtual void spawnResources(TileSource *, int, int, int, int, float);
	virtual void spawnBurnResources(TileSource *, float, float, float);
	virtual float getExplosionResistance(Entity *);
	virtual void clip(TileSource *, int, int, int, const Vec3 &, const Vec3 &, bool, int);
	virtual void wasExploded(TileSource *, int, int, int);
	virtual void use(Player *, int, int, int);
	virtual void stepOn(Entity *, int, int, int);
	virtual void fallOn(TileSource *, int, int, int, Entity *, float);
	virtual void getPlacementDataValue(Mob *, int, int, int, signed char, float, float, float, int);
	virtual void prepareRender(TileSource *, int, int, int);
	virtual void attack(Player *, int, int, int);
	virtual void handleEntityInside(TileSource *, int, int, int, Entity *, Vec3 &);
	virtual int getColor(int);
	virtual int getColor(TileSource *, int, int, int);
	virtual bool isSignalSource();
	virtual void getSignal(TileSource *, int, int, int);
	virtual void getSignal(TileSource *, int, int, int, int);
	virtual void getDirectSignal(TileSource *, int, int, int, int);
	virtual void entityInside(TileSource *, int, int, int, Entity *);
	virtual void playerDestroy(Player *, int, int, int, int);
	virtual bool canSurvive(TileSource *, int, int, int);
	virtual void setNameId(const std::string &);
	virtual void getName(const ItemInstance *) const;
	virtual void triggerEvent(TileSource *, int, int, int, int, int);
	virtual int getTextureNum(int);
	virtual void getMobToSpawn(TileSource &, const TilePos &) const;
	virtual void getIconYOffset() const;
	virtual void setShape(float, float, float, float, float, float);
	virtual void setSoundType(const Tile::SoundType &);
	virtual void setLightBlock(Brightness);
	virtual void setLightEmission(float);
	virtual void setExplodeable(float);
	virtual void setDestroyTime(float);
	virtual void setTicking(bool);
	virtual void getSpawnResourcesAuxValue(int);
	virtual void init();
	static void initTiles();
	static Tile *getLightEmission(TileID);
	static TextureAtlasTextureItem getTextureItem(const std::string &);
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string &, int);
	static Material *getTileMaterial(int);
	static bool isFaceVisible(TileSource *, int, int, int, signed char);
	static bool isTileType(const FullTile &, TileType);
	static void setTextureAtlas(std::shared_ptr<TextureAtlas>);
	static void teardownTiles();
	void _getTypeToSpawn(TileSource &, int, const TilePos &) const;
	void addAABB(const AABB &, const AABB *, std::vector<AABB> &);
	void destroyEffect(TileSource &, const TilePos &, const Vec3 &);
	float getShadeBrightness() const;
	bool isLiquidTile() const;
	bool isObstructingChests(TileSource *, const TilePos &);
	void popResource(TileSource *, int, int, int, const ItemInstance &);
	void setCategory(int);
	void transformToValidBlockId(TileID);
	void transformToValidBlockId(TileID, int, int, int);
};
