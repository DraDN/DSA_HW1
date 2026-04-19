#include <iostream>
#include <assert.h>

#include "TaskFlowManager.hpp"

int main() {
    tfm::TaskFlowManager task_manager;
    const tfm::ErrorType add_result = task_manager.addTask(100, "Task 1", 1);
    assert(add_result == tfm::ErrorType::SUCCESS);

    const tfm::ErrorType add_result_2 = task_manager.addTask(100, "Task 2", 1);
    assert(add_result_2 == tfm::ErrorType::FAILURE_DUPLICATE_ID);

    const tfm::ErrorType add_result_3 = task_manager.addTask(101, "Task 3", 6);
    assert(add_result_3 == tfm::ErrorType::FAILURE_INVALID_PRIORITY);

    return 0;
}