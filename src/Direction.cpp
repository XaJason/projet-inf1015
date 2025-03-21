#include "Direction.h"

namespace std {
	template<> struct hash<Direction> {
		size_t operator()(const Direction& direction) const noexcept {
			return std::hash<int>{}(static_cast<int>((direction)));
		}
	};
}
