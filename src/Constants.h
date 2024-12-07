#pragma once
#include "Direction.h"
#include <string>
#include <unordered_map>

namespace constants {
	extern const std::unordered_map<game_helper::Direction, std::vector<std::string>> directionNames;
}