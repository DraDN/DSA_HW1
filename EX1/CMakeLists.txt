add_executable(EX1 src/main.cpp)
target_include_directories(EX1 PRIVATE include)

add_subdirectory(tests)