#include "Constants.h"

using namespace game_helper;

namespace constants {
	const std::unordered_map<Direction, std::vector<std::string>> directionNames = {
	{Direction::north, {"North (N)", "n", "North"}},
	{Direction::south, {"South (S)", "s", "South"}},
	{Direction::west, {"West (W)", "w", "West"}},
	{Direction::east, {"East (E)", "e", "East"}}
	};
}