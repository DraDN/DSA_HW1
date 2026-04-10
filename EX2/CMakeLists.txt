add_library(EX2 STATIC src/library.cpp)
target_include_directories(EX2 PRIVATE include)

add_subdirectory(tests)