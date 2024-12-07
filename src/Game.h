#pragma once
#include "TileMap.h"
#include "Player.h"

namespace game_logic {
	class Game {
	public:
		Game(const game_world::TileMap& map, const game_world::Player& player);
		
		void startGame();
		void moveInDirection(game_helper::Direction direction, std::string item);
		void look(string details);
	private:
		game_world::TileMap map_;
		game_world::Player player_;
	};
}
