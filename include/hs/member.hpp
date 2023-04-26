#pragma once

#include <chrono>
#include <cstddef>
#include <string>

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

	//
	std::string fullname() const {
		return this->first_name + " " + this->last_name;
	}

	std::string id;
	std::string first_name;
	std::string last_name;

	std::chrono::system_clock::time_point birth;
};

}  // namespace hs
