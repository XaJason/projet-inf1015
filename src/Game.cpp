#include "Game.h"
#include <iostream>
#include <functional>
#include <unordered_map>
#include "Exceptions.h"
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost::algorithm;
using namespace game_engine;

Game::Game(const game_universe::TileMap& map, const game_universe::Player& player)
	: map_(map), player_(player) {
	player_.setPosition(((map_.getStartingTile()).lock()));
}

void Game::startGame() {
	static const std::unordered_map<std::string, std::function<void()>> commands = {
		{"n", [this]() { player_.move(Direction::north); }},
		{"s", [this]() { player_.move(Direction::south); }},
		{"w", [this]() { player_.move(Direction::west); }},
		{"e", [this]() { player_.move(Direction::east); }},

		{"north", [this]() { player_.move(Direction::north); }},
		{"south", [this]() { player_.move(Direction::south); }},
		{"west", [this]() { player_.move(Direction::west); }},
		{"east", [this]() { player_.move(Direction::east); }},

		{"u", [this]() { player_.move(Direction::north); }},
		{"d", [this]() { player_.move(Direction::south); }},
		{"r", [this]() { player_.move(Direction::east); }},

		{"up", [this]() { player_.move(Direction::north); }},
		{"down", [this]() { player_.move(Direction::south); }},
		{"left", [this]() { player_.move(Direction::west); }},
		{"right", [this]() { player_.move(Direction::east); }},

		{ "look", []() {} },
		{"1", [this]() { player_.move(Direction::south); }},
		{"2", [this]() { player_.move(Direction::west); }},
		{"3", [this]() { player_.move(Direction::east); }}


	};

	std::cout << ">>>>> INF1015 DUNGEON CRAWLER 2024 <<<<<\n" << "> > > > GAME OF THE YEAR EDITION < < < <\n\n" << "Map: " << map_.getName() << "\n\n" << player_ << "\n";
	while (true) {
		cout << "> ";
		string input;
		cin >> input;
		to_lower(input);

		try {
            commands.at(input)();
			cout << player_;
		}
		catch (InvalidMovement) {
			cout << "Well, urmmm, actually, you can't go there\n";
		}
		catch (out_of_range) {
			cout << "Urmmm, what the sigma is that input?\n";
		}
		
		cout << "\n";
	}
}