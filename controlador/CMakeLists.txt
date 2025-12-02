
file(GLOB CONTROLADOR_SOURCES "*.cpp")

add_library(controlador ${CONTROLADOR_SOURCES})

target_include_directories(controlador
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(controlador modelos)

