cmake_minimum_required(VERSION 3.27.7)

# The default build type must be set before project()
#if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR AND NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
#  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
#  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
#endif()

project(LightYears VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS       OFF)

add_executable(LightYearsGame
	${CMAKE_CURRENT_SOURCE_DIR}/LightYears/src/main.cpp
)


