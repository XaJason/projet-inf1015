#pragma once

#include "TileMap.h"
#include <map>
#include <unordered_set>

using namespace game_universe;

class LevelManager {
public:
	void addLevel(const std::string& name, std::shared_ptr<TileMap> level);
private:
	std::unordered_map<std::string, std::shared_ptr<TileMap>> levels;
};