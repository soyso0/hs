#pragma once

#include <chrono>
#include <cstddef>
#include <string>

#include "hs/types.hpp"

namespace hs {

class Member {
   public:
	enum class Kind {
		Unspecified = 0,

		Normal,
		Business,
	};

	virtual Kind kind() = 0;

	// ageAt returns the age of this `Member` at given time point.
	// @warning it does not consider leap year on current implementation.
	std::size_t ageAt(std::chrono::system_clock::time_point time) const;

	// ageNow returns ...
	// @warning it does not consider leap year on current implementation.
	inline std::size_t ageNow() const {
		return ageAt(std::chrono::system_clock::now());
	}

	std::string id;
	std::string password;
	Name        name;

	std::chrono::system_clock::time_point birth;
	std::chrono::system_clock::time_point created_at;
};

inline std::string to_string(Member::Kind kind) {
	switch(kind) {
	case Member::Kind::Normal: return "Normal";
	case Member::Kind::Business: return "Business";

	default: return "Unknown";
	}
}

class NormalMember: public Member {
   public:
	Kind kind() override {
		return Kind::Normal;
	}
};

class BusinessMember: public Member {
   public:
	Kind kind() override {
		return Kind::Business;
	}

	std::string company;
};

}  // namespace hs
