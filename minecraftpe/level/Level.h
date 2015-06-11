#pragma once

#include <unordered_set>
#include "TileSourceListener.h"
#include "LevelStorage.h"
#include "ParticleType.h"
#include "../entity/Entity.h"
#include "../client/AppPlatformListener.h"
#include "../util/Random.h"

class Player;
class Random;
class MobFactory;
class SoundPlayer;
class TileSource;
class TilePos;
class FullTile;
class EntityDamageSource;
class LightLayer;
class LevelChunk;
class Vec3;
class AABB;
class Material;
class LevelData;
class EntityUniqueID;
class LevelListener;
class LevelEvent;
class LevelSettings;
typedef int StorageVersion;

enum GeneratorType
{

};

// Size : 2996
class Level : public TileSourceListener, public AppPlatformListener
{
public:
	//void **vtable;						// 4
	//std::unordered_set<Player *> players;	// 60
	char filler1[88];						// 8
	Random random;							// 96
	MobFactory *mobFactory;					// 2908

public:
	Level(SoundPlayer &, std::unique_ptr<LevelStorage>, const std::string &, const LevelSettings &, bool);
	virtual ~Level();
	virtual void onSourceCreated(TileSource *);
	virtual void onSourceDestroyed(TileSource *);
	virtual void onTileChanged(TileSource *, const TilePos &, FullTile, FullTile, int);
	virtual void isNaturalDimension();
	virtual void addEntity(std::unique_ptr<Entity>);
	virtual void addPlayer(Player *);
	virtual void onPlayerDeath(Player &, EntityDamageSource &);
	virtual void tick();
	virtual void directTickEntities();
	virtual void updateSleepingPlayerList();
	virtual void setDifficulty(int);
	virtual void runLightUpdates(TileSource &, const LightLayer &, const TilePos &, const TilePos &);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	virtual void onChunkLoaded(LevelChunk &);
	virtual void removeEntity(std::unique_ptr<Entity> &&);
	virtual void removeEntity(Entity &);
	virtual void onAppSuspended();
	virtual void onAppResumed();
	void _chunkDirty(TileSource *, LevelChunk *);
	void _cleanupDisconnectedPlayers();
	void _createGenerator(GeneratorType);
	void _createLevelSources();
	void _destroyEffect(const TilePos &, FullTile, const Vec3 &);
	void _removeAllPlayer();
	void _saveDirtyChunks();
	void _saveSomeDirtyChunks();
	void _syncTime(long);
	void _updateLightRamp();
	void addListener(LevelListener *);
	bool addParticle(ParticleType, const Vec3 &, const Vec3 &, int);
	void animateTick(Entity *);
	void broadcastEntityEvent(Entity *, char);
	void broadcastLevelEvent(LevelEvent, const Vec3 &, int, Player *);
	void checkAndHandleWater(const AABB &, const Material *, Entity *);
	void destroyEffent(TileSource &, int, int, int, const Vec3 &);
	void destroyTile(TileSource &, const TilePos &, bool);
	void explode(Entity *, float, float, float, float);
	void explode(Entity *, float, float, float, float, bool);
	void extinguishFire(TileSource &, int, int, int, signed char);
	void findPath(Entity *, Entity *, float, bool, bool, bool, bool);
	void findPath(Entity *, int, int, int, float, bool, bool, bool, bool);
	void forceRemoveEntity(Entity &);
	void getChunkSource();
	void getCloudColor(float);
	void getCurrentTick();
	void getDefaultSpawn();
	char getDifficulty() const;
	Entity *getEntity(EntityUniqueID, bool);
	void getEntityIdMap();
	LevelData *getLevelData();
	LevelStorage *getLevelStorage();
	void getLightsToUpdate();
	void getLocalPlayer();
	void getMob(EntityUniqueID);
	void getMobSpawner();
	void getMoonBrightness() const;
	void getMoonPhase();
	Player *getNearestPlayer(Entity *, float);
	Player *getNearestPlayer(float, float, float, float);
	void getNewUniqueID();
	void getOldSkyDarken(float);
	Player *getPlayer(EntityUniqueID);
	Player *getPlayer(const std::string &);
	Player *getPlayerByClientId(uint);
	void getPlayerNames();
	Player *getRandomPlayer();
	void getSeaLevel();
	void getSeed();
	void getSharedSpawnPos();
	void getSkyColor(const Entity &, float);
	void getSkyColor(TileSource &, const TilePos &, float);
	void getSkyDarken(float);
	void getStarBrightness(float);
	void getSunAnble(float);
	void getSunIntensity(float, const Entity &, float);
	void getSunlightDirection(float);
	void getSunriseColor(float);
	long getTime() const;
	void getTimeOfDay(float);
	void getTimeSinceCreation();
	void handleLevelEvent(LevelEvent, const Vec3 &, int);
	bool isDay();
	bool isNightMode();
	void loadPlayer(Player &, bool);
	void mayInteract(Player *, int, int, int);
	void playSound(Entity *, const std::string &, float, float);
	void playSound(float, float, float, const std::string &, float, float);
	void removeAllPlayers();
	void removeListener(LevelListener *);
	void saveGameData();
	void saveLevelData();
	void savePlayers();
	void setDayCycleActive(bool);
	void setDefaultSpawn(const TilePos &);
	void setNightMode(bool);
	void setSpawnSettings(bool, bool);
	void setTime(long);
	void tickEntities();
	void tickTemporaryPointers();;
	void updateLights();
	void upgradeStorageVersion(StorageVersion);
};
