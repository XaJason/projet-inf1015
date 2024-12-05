#include "TileMap.h"
#include "memory"

using namespace gameWorld;

// PUBLIC
// Constructors
// Default constructor
TileMap::TileMap() : tiles_(height_, std::vector<Tile>(width_)), currentTile_(nullptr) {}

// L-value constructor
TileMap::TileMap(const Tile& tile) : tiles_(height_, std::vector<Tile>(width_)), currentTile_(std::make_shared<Tile>(tile)) { tiles_[height_ / 2][width_ / 2] = *currentTile_; }

// R-value constructor
TileMap::TileMap(Tile&& tile) noexcept : tiles_(height_, std::vector<Tile>(width_)), currentTile_(nullptr) {
	auto& centerTile = tiles_[height_ / 2][width_ / 2];
	centerTile = std::move(tile);
	currentTile_ = std::make_shared<Tile>(centerTile);
}

// Methods
void TileMap::addTile(const Tile& tile, size_t row, size_t column) {
	if (currentTile_ != nullptr)
		tiles_[row][column] = tile;
}