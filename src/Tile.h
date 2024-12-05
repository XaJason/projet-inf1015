#pragma once
#include <string>

namespace gameWorld {
	class Tile {
	public:
		Tile() = default;
		Tile(std::string name, std::string description);

		std::string getName() const { return name_; }
		std::string getDescription() const { return description_; }

	protected:

	private:
		std::string name_, description_;
	};
}