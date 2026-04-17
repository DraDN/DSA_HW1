#include <iostream>

#include "TaskFlowManager.hpp"


int main() {
    tfm::TaskFlowManager task_manager;
    auto add_result = task_manager.addTask(100, "Task 1", 1);
    if (add_result != tfm::ErrorType::SUCCESS) {
        std::cout << "Failed to add task" << std::endl;
    }
    
    auto result = task_manager.searchTaskByID(100);

    if (result != std::nullopt) {
        std::cout << result->getId() << std::endl;
    } else {
        std::cout << "Task not found" << std::endl;
    }

    auto result2 = task_manager.searchTaskByID(200);

    if (result2 != std::nullopt) {
        std::cout << result2->getId() << std::endl;
    } else {
        std::cout << "Task not found" << std::endl;
    }

    return EXIT_SUCCESS;
}