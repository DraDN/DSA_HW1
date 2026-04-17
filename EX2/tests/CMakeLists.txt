add_executable(TEST_TLM test.cpp)
target_link_libraries(TEST_TLM PUBLIC TLM)

add_test(NAME EX2_TEST COMMAND TEST_TLM)