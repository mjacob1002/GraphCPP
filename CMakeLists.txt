cmake_minimum_required(VERSION 3.10)
project(CPPGRAPH)
set(CMAKE_BUILD_TYPE=Debug)
set(SOURCE src)
set (CMAKE_CXX_FLAGS "-g")

add_executable(main ${SOURCE}/main.cpp ${SOURCE}/graph.cpp)
target_include_directories(main PRIVATE include/)

message("BUILDING THE SHARED LIBRARY graphcpp")
add_library(graphcpp SHARED 
src/graph.cpp
src/MST/DisjointSet.cpp
)
target_include_directories(graphcpp PRIVATE include/)
message("BUILT SHARED LIBRARY graphcpp")

if(BUILD_TESTS)
	add_subdirectory(tests)
endif()
