#pragma once

class Level;
class ChunkSource;
class Player;
class TilePos;
class FullTile;
class LightLayer;
class TileID;

class TileSource {
public:
	TileSource(Level &, ChunkSource *, bool, bool);
	TileSource(Player &);
	virtual ~TileSource();
	Level *getLevel() const;
	FullTile getTile(int, int, int);
	Tile *getTilePtr(int, int, int);
	void setTile(int, int, int, TileID, int);
	void setTileAndData(int, int, int, FullTile, int);
	int getBrightness(const LightLayer &, const TilePos &);
	int getBrightness(const LightLayer &, int, int, int);
	int getBrightness(const TilePos &);
	int getBrightness(int, int, int);
};
