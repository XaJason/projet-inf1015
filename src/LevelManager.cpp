#include "LevelManager.h"

void LevelManager::addLevel(const std::string& name, std::shared_ptr<TileMap> level) {
	levels[name] = level;
}