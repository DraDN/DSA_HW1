#include <iostream>

#include "TaskFlowManager.hpp"
#include "menu_functions.hpp"

tfm::TaskFlowManager task_manager;

int main() {
    // tfm::TaskFlowManager task_manager;
    // auto add_result = task_manager.addTask(100, "Task 1", 1);
    // if (add_result != tfm::ErrorType::SUCCESS) {
    //     std::cout << "Failed to add task" << std::endl;
    // }
    
    // auto result = task_manager.searchTaskByID(100);

    // if (result != std::nullopt) {
    //     std::cout << result->getId() << std::endl;
    // } else {
    //     std::cout << "Task not found" << std::endl;
    // }

    // auto result2 = task_manager.searchTaskByID(200);

    // if (result2 != std::nullopt) {
    //     std::cout << result2->getId() << std::endl;
    // } else {
    //     std::cout << "Task not found" << std::endl;
    // }


    int taskChoice = -1;

    while (taskChoice != 0) {
        menu::display_menu();

        if(!(std::cin >> taskChoice)){
            std::cout << "Invalid input. Enter a number.\n";
            continue;
        }

        switch (taskChoice) {
            case 1: {
                menu::add_task();
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