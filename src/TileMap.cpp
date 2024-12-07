#include "TileMap.h"
#include "memory"
#include <cassert>
#include <cmath>
#include "Exceptions.h"
#include <iostream>

using namespace std;

namespace game_world {

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
}
