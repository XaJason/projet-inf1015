#pragma once
#include <stdexcept>

class InvalidMovement : public std::out_of_range {
public:
	using std::out_of_range::out_of_range;
};