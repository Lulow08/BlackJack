find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TEST_FILES
    test_carta.cpp
    test_mazo.cpp
    test_apuesta.cpp
    test_participante.cpp
    test_serializador.cpp
    test_crupier.cpp
)

add_executable(run_tests ${TEST_FILES})


target_link_libraries(run_tests 
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
    pthread
    modelos
    controlador
    vista
)

add_test(NAME AllTests COMMAND run_tests)