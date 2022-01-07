cmake_minimum_required(VERSION 3.14)
# Project information
project(Airdata
  VERSION 3.1.0
  DESCRIPTION "Airdata functions."
  LANGUAGES CXX
)
include(FetchContent)
# Fetch global defs
FetchContent_Declare(
	units
	GIT_REPOSITORY https://github.com/bolderflight/units.git
	GIT_TAG v4.1.0
)
FetchContent_MakeAvailable(units)
# Add the library target
add_library(airdata INTERFACE)
target_link_libraries(airdata
	INTERFACE
		units
)
# Setup include directories 
target_include_directories(airdata INTERFACE src/)

# Example and unit testing if this project is built separately
if (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
	# Add the example target
	add_executable(airdata_example examples/cmake/airdata_example.cc)
	# Add the includes
	target_include_directories(airdata_example PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the example target
	target_link_libraries(airdata_example
		PRIVATE 
			airdata
	)
	# Fetch google test
	include(FetchContent)
	FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG release-1.10.0
	)
	FetchContent_MakeAvailable(googletest)
	enable_testing()
	include(GoogleTest)
	# Add the test target
	add_executable(airdata_test tests/airdata_test.cc)
	# Add the includes
	target_include_directories(airdata_test PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the test target
	target_link_libraries(airdata_test
		PRIVATE 
			airdata
			gtest_main 
			gtest
			gmock
	)
	# Discover unit tests
	gtest_discover_tests(airdata_test)
endif()
