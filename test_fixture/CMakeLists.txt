cmake_minimum_required(VERSION 3.15.2)

include_directories(${CMAKE_SOURCE_DIR}/googletest_R1100/googletest/googletest/include)
include_directories(${CMAKE_SOURCE_DIR}/googletest_R1100/googletest/googlemock/include)

add_subdirectory(googletest_R1100)

add_executable(test_fixture test_fixture.cpp)
target_link_libraries(test_fixture 	
	gtest_main
	gmock
	gtest 
	pthread)
