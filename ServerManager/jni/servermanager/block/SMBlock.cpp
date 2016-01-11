#include "servermanager/block/SMBlock.h"

BlockFace SMBlock::notchToBlockFace(int notch)
{
	switch (notch)
	{
	case 0:
		return BlockFace::DOWN;
	case 1:
		return BlockFace::UP;
	case 2:
		return BlockFace::NORTH;
	case 3:
		return BlockFace::SOUTH;
	case 4:
		return BlockFace::WEST;
	case 5:
		return BlockFace::EAST;
	default:
		return BlockFace::SELF;
	}
}
