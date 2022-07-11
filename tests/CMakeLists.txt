message("Building Tests")
add_executable(tests test_disjoint_set.cpp)
message("This is the CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(tests PUBLIC graphcpp)



