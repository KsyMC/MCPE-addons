#ifndef __TILESOURCE_H__
#define __TILESOURCE_H__

class Level;
class ChunkSource;
class Player;
struct TilePos;
struct FullTile;
struct LightLayer;

class TileSource {
public:
	TileSource(Level &, ChunkSource *, bool, bool);
	TileSource(Player &);
	virtual ~TileSource();
	Level *getLevel() const;
	FullTile getTile(int, int, int);
	Tile *getTilePtr(int, int, int);
	void setTile(int, int, int, TileID, int);
	int getBrightness(const LightLayer &, const TilePos &);
	int getBrightness(const LightLayer &, int, int, int);
	int getBrightness(const TilePos &);
	int getBrightness(int, int, int);
};

#endif
