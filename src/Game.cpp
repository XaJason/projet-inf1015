#include "Game.h"
#include <iostream>

using namespace game_engine;

Game::Game(const game_universe::TileMap& map, const game_universe::Player& player)
	: map_(map), player_(player) {
	player_.setPosition(((map_.getStartingTile()).lock()));
}

void Game::startGame() {
}