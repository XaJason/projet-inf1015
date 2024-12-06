#include "Tile.h"
#include <boost/functional/hash.hpp>
#include <unordered_map>

using namespace std;

namespace game_universe {

    // PUBLIC
    // Constructors
    void Tile::connect(const std::shared_ptr<Tile>& other, Direction direction) {
        connections_[direction] = other;
    }

    void Tile::connect(const std::shared_ptr<Tile>& northTile, const std::shared_ptr<Tile>& southTile, const std::shared_ptr<Tile>& westTile, const std::shared_ptr<Tile>& eastTile) {
        connect(northTile, Direction::north);
        connect(southTile, Direction::south);
        connect(westTile, Direction::west);
        connect(eastTile, Direction::east);
    }

    std::ostream& operator<<(std::ostream& outputStream, const Tile& tile)
    {
        static const unordered_map<Direction, string> directionNames = {
            {Direction::north, "North (N)"},
            {Direction::south, "South (S)"},
            {Direction::west, "West (W)"},
            {Direction::east, "East (E)"}
        };

        outputStream
            << "-- " << tile.name_ << " --\n"
            << tile.description_ << "\n";

        //for (int i = 0; i < tile.connections_.size(); i++) {
        //    if (const auto& temp = tile.connections_[i].lock())
        //        Direction temp2 = i;
        //    outputStream << temp->name_ << "is to the" << directionNames[i];
        //}
        return outputStream;
    }
    
}