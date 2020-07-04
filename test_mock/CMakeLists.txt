cmake_minimum_required(VERSION 3.15.2)


include_directories(${CMAKE_SOURCE_DIR}/googletest_R1100/googletest/googletest/include)
include_directories(${CMAKE_SOURCE_DIR}/googletest_R1100/googletest/googlemock/include)

add_subdirectory(googletest_R1100)
add_subdirectory(APP_SOURCES)
add_subdirectory(MOCK)

add_executable(test_mock test_mock_unit.cpp)
target_include_directories(test_mock PUBLIC "${CMAKE_SOURCE_DIR}/APP_SOURCES/inc")
target_include_directories(test_mock PUBLIC "${CMAKE_SOURCE_DIR}/APP_SOURCES")
target_include_directories(test_mock PUBLIC "${CMAKE_SOURCE_DIR}/MOCK/inc")

target_link_libraries(test_mock 
gtest_main
gmock
gtest
pthread 
user_app 
mock_interface)
