#pragma once

#include <string>

namespace hs {

struct Name {
	std::string full() const {
		return this->first + " " + this->middle + " " + this->last;
	}

	std::string first;
	std::string middle;
	std::string last;
};

}  // namespace hs
