#include "hs/utils.hpp"

#include <cstddef>
#include <random>
#include <string>

namespace hs {

std::string randomString(std::size_t len) {
	static std::string  alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static std::mt19937 generator(std::random_device{}());

	static std::uniform_int_distribution<int> distribution{0, alphabet.size()};

	std::string rst;
	rst.reserve(len);
	for(std::size_t i = 0; i < len; ++i) {
		rst.push_back(alphabet.at(distribution(generator)));
	}

	return rst;
}

}  // namespace hs
