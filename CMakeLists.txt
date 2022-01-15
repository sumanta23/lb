cmake_minimum_required(VERSION 3.5.1)

project(samlb LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 11)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

FIND_PACKAGE(Boost COMPONENTS system REQUIRED)
FIND_PACKAGE(PkgConfig REQUIRED)
IF(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
ENDIF(Boost_FOUND)


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
    PRIVATE ${Boost_SYSTEM_LIBRARY}  
	PRIVATE Threads::Threads
)

