


add_library(mock_interface src/interface_app.cpp)
target_include_directories(mock_interface PUBLIC inc)
target_include_directories(mock_interface PUBLIC "${CMAKE_SOURCE_DIR}/APP_SOURCES/inc")


target_link_libraries(mock_interface   
gtest_main
gmock
gtest
pthread user_app)
