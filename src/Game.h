#pragma once
#include "TileMap.h"
#include "Player.h"

namespace game_engine {
	class Game {
	public:
		Game(const game_universe::TileMap& map, const game_universe::Player& player);
		
		void startGame();
	/*private:*/
		game_universe::TileMap map_;
		game_universe::Player player_;
	};
}
