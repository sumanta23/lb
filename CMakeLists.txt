cmake_minimum_required(VERSION 3.5.1)

project(samlb LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 11)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/bin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third/spdlog/include/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third/cpp-httplib/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third/nlohmann/)

add_definitions(-DCPPHTTPLIB_THREAD_POOL_COUNT)

add_executable(samlb src/main.cpp src/LeaderBoard/Leaderboard.cpp )

target_link_libraries(samlb
)

