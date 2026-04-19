add_executable(TEST_ADD_TASK add_task_test.cpp)
target_link_libraries(TEST_ADD_TASK PUBLIC TFM)

add_test(NAME EX1_ADD_TASK COMMAND TEST_ADD_TASK)

add_executable(TEST_SEARCH_TASK search_task_test.cpp)
target_link_libraries(TEST_SEARCH_TASK PUBLIC TFM)

add_test(NAME EX1_SEARCH_TASK COMMAND TEST_SEARCH_TASK)

add_executable(TEST_PROCESS_TASK process_tasks_test.cpp)
target_link_libraries(TEST_PROCESS_TASK PUBLIC TFM)

add_test(NAME EX1_PROCESS_TASK COMMAND TEST_PROCESS_TASK)

add_executable(TEST_UNDO_TASK undo_task_test.cpp)
target_link_libraries(TEST_UNDO_TASK PUBLIC TFM)

add_test(NAME EX1_UNDO_TASK COMMAND TEST_UNDO_TASK)