cmake_minimum_required(VERSION 3.21)

project(
	"hs"
		VERSION   0.0.1
		LANGUAGES CXX
)

option(${PROJECT_NAME}_TESTS "Enable ${PROJECT_NAME} tests targets." ${PROJECT_IS_TOP_LEVEL})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_library(
	hs
		include/hs/member_store.hpp
		include/hs/member.hpp
		include/hs/time.hpp

		src/member_store.cpp
		src/member.cpp
)
target_include_directories(
	hs PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)

add_executable(
	hs-app
		app/main.cpp
)
target_link_libraries(
	hs-app PRIVATE
		hs
)


if(${PROJECT_NAME}_TESTS)
	add_subdirectory(tests)
endif()
