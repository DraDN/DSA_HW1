#include "menu_functions.hpp"

#include "TaskFlowManager.hpp"

#include <iostream>

extern tfm::TaskFlowManager task_manager;


void menu::display_menu() {
    std::cout << "==============================\n";
    std::cout << "Interactive Task Flow Manager\n";
    std::cout << "==============================\n";
    std::cout << "1. Add new Task\n";
    std::cout << "2. Process next task\n";
    std::cout << "3. Undo last processed task\n";
    std::cout << "4. Display waiting tasks\n";
    std::cout << "5. Display processed task history\n";
    std::cout << "6. Process next k tasks\n";
    std::cout << "7. Search task by id\n";
    std::cout << "8. Display statistics\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose option:";
}

void menu::add_task() {
    unsigned int id;
    std::string description;
    short priority;

    std::cin >> id;
    // std::cin.ignore();
    // std::getline(std::cin, description);
    // std::cin.ignore();
    std::cin >> description;
    std::cin >> priority;

    tfm::ErrorType addTaskResult = task_manager.addTask(id, description.c_str() , priority);

    if (addTaskResult == tfm::ErrorType::SUCCESS) {
        std::cout << "Task added succesfully: \n";
        std::cout << "ID: " << id << ", Description: " << description << ", Priority: " << priority << std::endl;
    }
    else if (addTaskResult == tfm::ErrorType::FAILURE_DUPLICATE_ID) {
        std::cout << "A task with ID: " << id << " already exists. \n";
    }
    else if (addTaskResult == tfm::ErrorType::FAILURE_INVALID_PRIORITY) {
        std::cout << "Priority must be between 1-5. \n";
    }
    else {
        std::cout << "Task could not be added. \n";
    }
}