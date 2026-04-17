add_library(TLM STATIC src/TimeLineManager.cpp)
target_include_directories(TLM PUBLIC include)

add_subdirectory(tests)

add_custom_target(
    run_ex2
    COMMAND TEST_TLM
    DEPENDS EX2
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    USES_TERMINAL
)