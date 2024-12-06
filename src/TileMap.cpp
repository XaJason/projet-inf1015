#include "TileMap.h"
#include "memory"
#include <cassert>
#include <cmath>
#include "Exceptions.h"
#include <iostream>

using namespace game_universe;

// PUBLIC
// Constructors
// Default constructor
void TileMap::addTile(const std::shared_ptr<Tile>& tile) {
	if (tile) {
		tiles_.push_back(tile);
		if (isStartingTileNull()) { // Checks if the currentTile is empty
			startingTile_ = tile;
		}
	}
}
