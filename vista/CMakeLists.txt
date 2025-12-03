file(GLOB VISTA_SOURCES "*.cpp")

add_library(vista ${VISTA_SOURCES})

target_include_directories(vista
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(vista modelos controlador)

