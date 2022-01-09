cmake_minimum_required(VERSION 3.5.1)

project(samlb LANGUAGES C CXX)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY $ENV{PROJECT_HOME}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $ENV{PROJECT_HOME}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $ENV{PROJECT_HOME}/bin)

include_directories($ENV{PROJECT_HOME}/)
include_directories($ENV{PROJECT_HOME}/src/include/)
include_directories($ENV{PROJECT_HOME}/third/spdlog/include/)
include_directories($ENV{PROJECT_HOME}/third/nlohmann/)



add_executable(samlb src/main.c src/LeaderBoard/Leaderboard.cpp )

target_link_libraries(samlb
)

