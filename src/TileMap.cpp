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
TileMap::TileMap(const TileMap& other) : name_(other.name_), tiles_(std::make_unique<std::unordered_map<std::string, std::unique_ptr<Tile>>>()), startingTile_(other.startingTile_) {
	for (auto& tile : *other.tiles_) {
		addTile(*tile.second);
	}
}

void TileMap::addTile(const Tile& tile) {
	auto newTile = make_unique<Tile>(tile);
	if (startingTile_ == nullptr) { // Checks if the currentTile is empty
		startingTile_ = newTile.get();
	}
	tiles_->emplace(newTile->getName(), move(newTile));
}

Tile* TileMap::operator[](const std::string& name) const {
	auto it = tiles_->find(name);
	return (it != tiles_->end() ? it->second.get() : nullptr);
}
