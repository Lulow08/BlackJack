cmake_minimum_required(VERSION 3.10)
project(Blackjack CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest setup
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/modelos"
    "${CMAKE_CURRENT_SOURCE_DIR}/controlador"
    "${CMAKE_CURRENT_SOURCE_DIR}/vista"
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_subdirectory(controlador)
add_subdirectory(modelos)
add_subdirectory(vista)
add_subdirectory(tests)

add_executable(blackjack main.cpp)

target_link_libraries(blackjack
    modelos
    controlador
    vista
)