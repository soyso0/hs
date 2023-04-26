#include <chrono>
#include <cstddef>
#include <utility>

#include "hs/member.hpp"

namespace hs {

std::size_t Member::ageAt(std::chrono::system_clock::time_point time) const {
	constexpr std::size_t HoursOfDay = 24;
	constexpr std::size_t DaysOfYear = 365;

	return std::chrono::duration_cast<std::chrono::hours>(time - this->birth).count() / HoursOfDay / DaysOfYear;
}

}  // namespace hs
