#include "Tile.h"
#include <boost/functional/hash.hpp>


using namespace gameWorld;

// PUBLIC
// Constructors
void Tile::connect(const std::shared_ptr<Tile>& other, Direction direction) {
    neighbors_[direction] = other;
}

void Tile::connect(const std::shared_ptr<Tile>& northTile, const std::shared_ptr<Tile>& southTile, const std::shared_ptr<Tile>& westTile, const std::shared_ptr<Tile>& eastTile) {
    connect(northTile, direction_north);
    connect(southTile, direction_south);
    connect(westTile, direction_west);
    connect(eastTile, direction_east);
}

bool Tile::operator==(const Tile& other) const {
	return name_ == other.getName() && description_ == other.description_;
}

bool TileEqual::operator()(const std::shared_ptr<Tile>& lhs, const std::shared_ptr<Tile>& rhs) const {
    if (!lhs || !rhs) {
        return lhs == rhs;
    }
    return *lhs == *rhs;
}

size_t TileHash::operator()(const std::shared_ptr<Tile>& tile) const {
    if (!tile) {
        return 0;
    }
    std::size_t seed = 0;
    boost::hash_combine(seed, tile->getName());
    boost::hash_combine(seed, tile->getDescription());
    return seed;
}