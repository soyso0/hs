#include <chrono>
#include <cstddef>
#include <ctime>

namespace hs {

// timePointFromDate returns time point of system clock at given date.
// @note all number are 1-based; the first day of the month is 1, the last month of the year is 12.
// @warning minimum representable year is 1900 on current implementation.
std::chrono::system_clock::time_point timePointFromDate(int day, int month, int year) {
	std::tm tm{0, 0, 0, day - 1, month - 1, year - 1900};
	return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

}  // namespace hs
