#pragma once
#include <string>
#include <memory>
#include <array>
#include "Direction.h"
#include <boost/functional/hash.hpp>
#include <unordered_map>
#include "Item.h"

using namespace std;
using namespace game_helper;

namespace game_world {
	class Tile {
	public:
		Tile(std::string name = "", std::string description = "") : name_(name), description_(description) {}

		void connect(const std::shared_ptr<Tile>& other, Direction direction);
		void connect(const std::shared_ptr<Tile>& northTile, const std::shared_ptr<Tile>& southTile, const std::shared_ptr<Tile>& westTile, const std::shared_ptr<Tile>& eastTile );
		void addItem(const Item& item);

		std::string getName() const { return name_; }
		std::string getDescription() const { return description_; }
		auto getConnections() const { return connections_; }
		std::weak_ptr<Tile> getConnection(Direction direction) const { 
			auto it = connections_.find(direction);
			if (it != connections_.end()) {
				return it->second;
			}
			return std::weak_ptr<Tile>();
		}

		friend std::ostream& operator<<(std::ostream& outputStream, const Tile& tile);

	private:
		std::string name_, description_;
		std::unordered_map<Direction, weak_ptr<Tile>> connections_;
		std::unordered_map<std::string, shared_ptr<Item>> items_;
	};
}