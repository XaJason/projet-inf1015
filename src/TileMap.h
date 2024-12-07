#pragma once

#include <vector>
#include <memory>
#include "Tile.h"
#include <ostream>
#include "Direction.h"
#include <map>
#include <functional>
#include <unordered_set>

namespace game_world {
	class TileMap {
	public:
		TileMap(std::string name = "") : name_(name) {}


		void addTile(const Tile& tile);

		const std::string& getName() const { return name_; }
		const std::unordered_map <std::string, std::shared_ptr<Tile>>& getTiles() const { return tiles_; }
		const std::weak_ptr<Tile>& getStartingTile() const { return startingTile_; }

		std::shared_ptr<Tile> operator[](const std::string& name) const { return tiles_.at(name); }

	private:
		std::string name_;
		std::unordered_map <std::string, std::shared_ptr<Tile>> tiles_;
		std::weak_ptr<Tile> startingTile_;
	};
}
