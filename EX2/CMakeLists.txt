add_library(EX2 STATIC src/library.cpp)
target_include_directories(EX2 PRIVATE include)

add_subdirectory(tests)

add_custom_target(
    run_ex2
    COMMAND TEST_TESTSEX2
    DEPENDS EX2
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    USES_TERMINAL
)