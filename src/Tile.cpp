#include "Tile.h"
#include <boost/functional/hash.hpp>


using namespace game_universe;

// PUBLIC
// Constructors
void Tile::connect(const std::shared_ptr<Tile>& other, Direction direction) {
    connections_[direction] = other;
}

void Tile::connect(const std::shared_ptr<Tile>& northTile, const std::shared_ptr<Tile>& southTile, const std::shared_ptr<Tile>& westTile, const std::shared_ptr<Tile>& eastTile) {
    connect(northTile, direction_north);
    connect(southTile, direction_south);
    connect(westTile, direction_west);
    connect(eastTile, direction_east);
}