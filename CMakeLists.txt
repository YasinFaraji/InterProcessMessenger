cmake_minimum_required(VERSION 3.10)
project(ConditionVariableIPC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(spdlog REQUIRED)

add_executable(condition_variable_ipc
    src/common.hpp
    src/initiator.hpp
    src/receiver.hpp
    src/thread_coordinator.hpp
    src/main.cpp
)

target_link_libraries(condition_variable_ipc PRIVATE spdlog::spdlog)
