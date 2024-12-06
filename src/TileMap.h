#pragma once

#include <vector>
#include <memory>
#include "Tile.h"
#include <ostream>
#include "Direction.h"
#include <map>
#include <functional>
#include <unordered_set>

namespace gameWorld {
	class TileMap {
	public:
		TileMap(std::string name = "", const std::shared_ptr<Tile>& tile = nullptr) : name_(name) { addTile(tile); };
		
		bool isCurrentNull() const { return currentTile_.lock() == nullptr; }
		void addTile(const std::shared_ptr<Tile>& tile);
		void connectTiles(const std::shared_ptr<Tile>& tile1, const std::shared_ptr<Tile>& tile2, const Direction& direction);
		
		void move(const Direction& direction);
	//private:
		std::string name_;
		std::vector < std::shared_ptr<Tile>> tiles_;
		std::weak_ptr<Tile> currentTile_;
	};
}
