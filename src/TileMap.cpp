#include "TileMap.h"
#include "memory"
#include <cassert>
#include <cmath>
#include "Exceptions.h"
#include <iostream>

using namespace gameWorld;

// PUBLIC
// Constructors
// Default constructor
void TileMap::addTile(const std::shared_ptr<Tile>& tile) {
	if (tile) {
		tiles_.push_back(tile);
		if (isCurrentNull()) { // Checks if the currentTile is empty
			currentTile_ = tile;
		}
	}
}

void TileMap::connectTiles(const std::shared_ptr<Tile>& tile1, const std::shared_ptr<Tile>& tile2, const Direction& direction) {
	tile1->connect(tile2, direction);
}

void TileMap::move(const Direction& direction) {
	if (auto origin = currentTile_.lock()) { // Verification initialization
		if (auto destination = origin->getNeighbors()[direction].lock()) {
			currentTile_ = destination;
		}
		else {
			throw InvalidMovement("Error : No accessible room in this direction.");
		}
	}

}