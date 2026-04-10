add_executable(EX1 src/main.cpp)
target_include_directories(EX1 PRIVATE include)

add_subdirectory(tests)

add_custom_target(
    run_ex1
    COMMAND EX1
    DEPENDS EX1
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    USES_TERMINAL
)