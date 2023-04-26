#pragma once

#include <chrono>
#include <cstddef>
#include <string>

#include "hs/types.hpp"

namespace hs {

class Member {
   public:
	// ageAt returns the age of this `Member` at given time point.
	// @warning it does not consider leap year on current implementation.
	std::size_t ageAt(std::chrono::system_clock::time_point time) const;

	// ageNow returns ...
	// @warning it does not consider leap year on current implementation.
	inline std::size_t ageNow() const {
		return ageAt(std::chrono::system_clock::now());
	}

	std::string id;
	Name        name;

	std::chrono::system_clock::time_point birth;
	std::chrono::system_clock::time_point created_at;
};

}  // namespace hs
