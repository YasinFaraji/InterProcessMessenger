cmake_minimum_required(VERSION 3.10)
project(IPC_SharedMemory)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Threads REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src)
file(GLOB SOURCES "src/*.cpp")

add_executable(ipc ${SOURCES})
target_link_libraries(ipc Threads::Threads)