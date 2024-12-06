#pragma once
#include <memory>
#include "Tile.h"

namespace game_universe {
	class Player {
	public:
		Player() = default;


		void move(const Direction& direction);

		bool isPositionNull() const { return position_.lock() == nullptr; }
		std::weak_ptr<Tile> getPosition() const { return position_; }
		void setPosition(const std::shared_ptr<Tile>& position) { position_ = position; }

	private:
		std::weak_ptr<Tile> position_;
	};
}