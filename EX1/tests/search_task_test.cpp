#include <iostream>
#include <assert.h>

#include "TaskFlowManager.hpp"

int main() {
    tfm::TaskFlowManager task_manager;

    const tfm::ErrorType add_result = task_manager.addTask(100, "Task 1", 1);
    assert(add_result == tfm::ErrorType::SUCCESS);

    const tfm::ErrorType add_result_2 = task_manager.addTask(101, "Task 2", 1);
    assert(add_result_2 == tfm::ErrorType::SUCCESS);

    const tools::Optional<tfm::Task> search_result = task_manager.searchTaskByID(100);
    assert(search_result != tools::nullopt);
    assert(search_result->getId() == 100);
    assert(search_result->getDescription() == "Task 1");
    assert(search_result->getPriority() == 1);

    return 0;
}