#include "Tile.h"
#include <boost/functional/hash.hpp>
#include <unordered_map>
#include "Constants.h"

using namespace std;
using namespace constants;

namespace game_world {

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

    void Tile::addItem(const Item& item) {
		items_[item.getName()] = make_shared<Item>(item);
    }

    std::ostream& operator<<(std::ostream& outputStream, const Tile& tile)
    {


        outputStream
            << "\t-- " << tile.name_ << " --\n"
            << "\t" << tile.description_ << "\n\n";

        for (const auto& [direction, connection] : tile.connections_) {
            if (const auto& sharedConnection = connection.lock()) {
                outputStream << "\t" << sharedConnection->name_ << " is to the " << ::directionNames.at(direction)[0] << "\n";
            }
        }
        return outputStream;
    }
    
}