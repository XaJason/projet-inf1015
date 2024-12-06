#pragma once
#include <string>
#include <memory>
#include <array>
#include "Direction.h"

namespace game_universe {
	class Tile {
	public:
		Tile(std::string name = "", std::string description = "") : name_(name), description_(description) {}

		void connect(const std::shared_ptr<Tile>& other, Direction direction);
		void connect(const std::shared_ptr<Tile>& northTile, const std::shared_ptr<Tile>& southTile, const std::shared_ptr<Tile>& westTile, const std::shared_ptr<Tile>& eastTile );

		std::string getName() const { return name_; }
		std::string getDescription() const { return description_; }
		std::array<std::weak_ptr<Tile>, 4> getNeighbors() const { return connections_; }
		std::weak_ptr<Tile> getConnection(Direction direction) const { return connections_[direction]; }

	private:
		std::string name_, description_;
		std::array<std::weak_ptr<Tile>, 4> connections_;
	};
}