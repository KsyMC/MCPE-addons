#pragma once

class TileSource;
class Entity;
class Node;

// Size : 172
class PathFinder
{
public:
	TileSource *tileSource;	// 0

public:
	PathFinder(TileSource *, bool, bool, bool, bool);
	~PathFinder();
	void findPath(Entity *, Entity *, float);
	void findPath(Entity *, Node *, Node *, Node *, float);
	void findPath(Entity *, float, float, float, float);
	void findPath(Entity *, int, int, int, float);
	void getNeighbors(Entity *, Node *, Node *, Node *, float);
	void getNode(Entity *, int, int, int, Node *, int);
	void getNode(int, int, int);
	void isFree(Entity *, int, int, int, Node *);
	void reconstruct_path(Node *, Node *);
};