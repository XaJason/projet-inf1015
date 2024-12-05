#pragma once

#include <vector>
#include <memory>
#include "Tile.h"

namespace gameWorld {
	class TileMap {
	public:
		TileMap();
		TileMap(const Tile& tile);
		TileMap(Tile&& tile) noexcept;
		
		//std::vector<std::vector<Tile>> getTiles() const { return tiles_; }
		//Tile getCurrentTile() const { return *currentTile_; }
		//void setCurrentTile(Tile tile) { currentTile_ = std::make_shared<Tile>(tile); }

		void addTile(const Tile& tile, size_t row, size_t column);

		std::vector<Tile>& operator[](size_t row) { return tiles_[row]; }

	protected:
	private:
		std::vector<std::vector<Tile>> tiles_;
		std::shared_ptr<Tile> currentTile_;
		static constexpr size_t height_ = 10;
		static constexpr size_t width_ = 10;
	};
}
