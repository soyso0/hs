include(FetchContent)

FetchContent_Declare(
	Catch2
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG	       v3.2.1
)
FetchContent_MakeAvailable(
	Catch2
)



enable_testing()
include(Catch)



add_custom_target(all-test)
macro (hs_SIMPLE_TEST NAME)
	add_executable(
		${NAME}-test
			src/${NAME}.cpp
	)
	target_include_directories(
		${NAME}-test PRIVATE
			include
	)
	target_link_libraries(
		${NAME}-test PRIVATE
			Catch2::Catch2WithMain
			hs
	)
	catch_discover_tests(${NAME}-test)

	add_dependencies(
		all-test
			${NAME}-test
	)
endmacro (hs_SIMPLE_TEST)

hs_SIMPLE_TEST(member)
