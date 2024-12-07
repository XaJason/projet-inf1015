#pragma once
#include <stdexcept>

namespace exceptions {
	class InvalidMovement : public std::out_of_range {
	public:
		using std::out_of_range::out_of_range;
	};
}