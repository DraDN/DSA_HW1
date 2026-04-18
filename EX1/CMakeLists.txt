add_library(TFM STATIC src/TaskFlowManager.cpp)
target_include_directories(TFM PUBLIC include)

add_executable(EX1 src/main.cpp
    src/menu_functions.cpp)
target_link_libraries(EX1 PRIVATE TFM)
target_include_directories(EX1 PRIVATE include)

add_subdirectory(tests)

add_custom_target(
    run_ex1
    COMMAND EX1
    DEPENDS EX1
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    USES_TERMINAL
)