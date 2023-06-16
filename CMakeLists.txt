cmake_minimum_required(VERSION 3.14)
# Project information
project(Airdata
  VERSION 4.0.0
  DESCRIPTION "Airdata functions."
  LANGUAGES CXX
)
include(FetchContent)
if (DEFINED DEPS)
  string(TOUPPER ${DEPS} DEPS)
  if (DEPS STREQUAL "BFS")
    # Fetch global defs
    FetchContent_Declare(
      units
      GIT_REPOSITORY git@192.168.1.11:bolderflight/software/units.git
      GIT_TAG v5.0.0
    )
  elseif(DEPS STREQUAL "LOCAL")
    # Fetch global defs
    FetchContent_Declare(
      units
      GIT_REPOSITORY ${CMAKE_SOURCE_DIR}/../units
      GIT_TAG v5.0.0
    )
  else()
    # Fetch global defs
    FetchContent_Declare(
      units
      GIT_REPOSITORY https://github.com/bolderflight/units.git
      GIT_TAG v5.0.0
    )
  endif()
else()
# Fetch global defs
FetchContent_Declare(
  units
  GIT_REPOSITORY https://github.com/bolderflight/units.git
  GIT_TAG v5.0.0
)
endif()
FetchContent_MakeAvailable(units)
# Add the library target
add_library(airdata
  src/airdata_constants.h
  src/airdata.h
  src/airdata.cpp
)
target_link_libraries(airdata
  PRIVATE
    units
)
# Setup include directories 
target_include_directories(airdata PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  $<INSTALL_INTERFACE:include>
)

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
    GIT_TAG release-1.12.1
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
