cmake_minimum_required(VERSION 3.10)
project(Blackjack CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${CMAKE_SOURCE_DIR}/modelos
    ${CMAKE_SOURCE_DIR}/controlador
    ${CMAKE_SOURCE_DIR}/vista
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