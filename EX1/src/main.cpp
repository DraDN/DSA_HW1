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


    int taskChoice = -1;


    while (taskChoice != 0) {
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

        if(!(std::cin >> taskChoice)){
            std::cout << "Invalid input. Enter a number.\n";
            continue;
        }

        switch (taskChoice) {
            case 1: {
                unsigned int id;
                std::string description;
                short priority;

                std::cin >> id;
                std::cin.ignore();
                std::getline(std::cin, description);
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
                break;
            }
            case 2: {
                
            }
            case 3: {
                
            }
            case 4: {
                
            }
            case 5: {
                
            }
            case 6: {
                
            }
            case 7: {

            }
            case 8: {
                
            }
            case 0: {
                std::cout << "Exiting Task Flow Manager.\n";
                break;
                
            }
        }

    }

    return EXIT_SUCCESS;
}