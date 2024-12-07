#pragma once
#include <unordered_map>
#include "Direction.h"
#include <string>

namespace constants {
	extern const std::unordered_map<game_helper::Direction, std::vector<std::string>> directionNames;
}