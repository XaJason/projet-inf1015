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
        static const std::unordered_map<Direction, std::vector<std::string>> directionNames = {
  {Direction::north, {"North (N)", "n"}},
  {Direction::south, {"South (S)", "s"}},
  {Direction::west, {"West (W)", "w"}},
  {Direction::east, {"East (E)", "e"}}
        };

        outputStream
            << "-- " << tile.name_ << " --\n"
            << tile.description_ << "\n";

        for (const auto& [direction, connection] : tile.connections_) {
            if (const auto& sharedConnection = connection.lock()) {
                outputStream << sharedConnection->name_ << " is to the " << directionNames.at(direction)[0] << "\n";
            }
        }
        return outputStream;
    }
    
}