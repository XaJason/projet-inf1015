#pragma once
#include <functional>

enum class Direction{
	north,
	south,
	west,
	east
};

namespace std {
	template<> struct std::hash<Direction> {
		size_t operator()(const Direction& direction) const noexcept {
			return std::hash<int>{}(static_cast<int>((direction)));
		}
	};
}