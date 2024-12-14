#include "Exceptions.h"
#include "memory"
#include "TileMap.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

// PUBLIC
// Constructors
// Default constructor
void TileMap::addTile(const Tile& tile) {
	auto owningCopy = make_shared<Tile>(tile);
	if (tiles_.empty()) { // Checks if the currentTile is empty
		startingTile_ = owningCopy;
	}
	tiles_[tile.getName()] = owningCopy;
}
