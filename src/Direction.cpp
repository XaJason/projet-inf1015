#include "Direction.h"

using namespace game_helper;

namespace std {
	template<> struct std::hash<Direction> {
		size_t operator()(const Direction& direction) const noexcept {
			return std::hash<int>{}(static_cast<int>((direction)));
		}
	};
}