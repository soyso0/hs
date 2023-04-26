#include <ctime>

#include <catch2/catch_test_macros.hpp>

#include "hs/member.hpp"
#include "hs/time.hpp"

TEST_CASE("Member") {
	using namespace hs;

	Member member{
	    .name = {
			.first= "Seunghyun",
			.last = "Hwang",
		}, 
	    .birth      = timePointFromDate(1, 3, 1995),
	};

	SECTION("::ageAt") {
		REQUIRE(28 == member.ageAt(timePointFromDate(28, 2, 2023)));  // leap year is not considered.
		REQUIRE(28 == member.ageAt(timePointFromDate(1, 3, 2023)));
		REQUIRE(28 == member.ageAt(timePointFromDate(2, 3, 2023)));
	}
}
