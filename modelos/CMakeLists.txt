file(GLOB MODELOS_SOURCES "*.cpp")

add_library(modelos ${MODELOS_SOURCES})

target_include_directories(modelos
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

