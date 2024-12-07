#pragma once
#include <string>

namespace game_world {
	class Item {
	public:
		Item(std::string name = "", std::string description = "") : name_(name), description_(description) {}
		std::string getName() const { return name_; }
		std::string getDescription() const { return description_; }
		friend std::ostream& operator<<(std::ostream& outputStream, const Item& item);

	private:
		std::string name_, description_;
	};
}