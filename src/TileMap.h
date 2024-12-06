#pragma once

#include <vector>
#include <memory>
#include "Tile.h"
#include <ostream>
#include "Direction.h"
#include <map>
#include <functional>
#include <unordered_set>

namespace game_universe {
	class TileMap {
	public:
		TileMap(std::string name = "", const std::shared_ptr<Tile>& tile = nullptr) : name_(name) { addTile(tile); };
		

		void addTile(const std::shared_ptr<Tile>& tile);

		const std::vector<std::shared_ptr<Tile>>& getTiles() const { return tiles_; }
		const std::weak_ptr<Tile>& getStartingTile() const { return startingTile_; }
		bool isStartingTileNull() const { return startingTile_.lock() == nullptr; }

	private:
		std::string name_;
		std::vector < std::shared_ptr<Tile>> tiles_;
		std::weak_ptr<Tile> startingTile_;
	};
}
