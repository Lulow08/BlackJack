file(GLOB TEST_SOURCES "*.cpp")

add_executable(test_runner ${TEST_SOURCES})

target_link_libraries(test_runner
    modelos
    controlador
    vista

    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_runner)