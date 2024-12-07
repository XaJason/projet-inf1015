#pragma once
#include "Tile.h"
#include <memory>
#include <ostream>

namespace game_world {
	class Player {
	public:
		Player() = default;

		void move(const game_helper::Direction& direction);
		void addItem(std::shared_ptr<Item> item) { items_[item->getName()] = std::move(item); }

		bool isPositionNull() const { return position_.lock() == nullptr; }
		std::weak_ptr<Tile> getPosition() const { return position_; }
		void setPosition(const std::shared_ptr<Tile>& position) { position_ = position; }

		friend std::ostream& operator<<(std::ostream& outputStream, const Player& player);

	private:
		std::weak_ptr<Tile> position_;
		std::unordered_map<std::string, shared_ptr<Item>> items_;
	};
}