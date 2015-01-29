#ifndef __TILEENTITYFACTORY_H__
#define __TILEENTITYFACTORY_H__

class TileEntity;
struct TilePos;

class TileEntityFactory {
public:
	static TileEntity *createTileEntity(TileEntityType, const TilePos &);
};

#endif
