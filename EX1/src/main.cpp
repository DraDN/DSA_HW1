#include <iostream>

#include "TaskFlowManager.hpp"
#include "menu_functions.hpp"

tfm::TaskFlowManager task_manager;

int main() {
    int taskChoice = -1;

    while (taskChoice != 0) {
        menu::display_menu();

        if(!(std::cin >> taskChoice)){
            std::cout << "\nInvalid input. Enter a number.\n";
            continue;
        }

        std::cout << "\n"; // separate menu options from result of input

        switch (taskChoice) {
            case 1: {
                menu::add_task();
                break;
            }
            case 2: {
                menu::process_next_task();
                break;
            }
            case 3: {
                menu::undo_last_processed_task();
                break;
            }
            case 4: {
                menu::display_waiting_tasks();
                break;
            }
            case 5: {
                menu::display_processed_task_history();
                break;
                
            }
            case 6: {
                menu::process_next_k_tasks();
                break;
            }
            case 7: {
                menu::search_task_by_id();
                break;

            }
            case 8: {
                menu::display_statistics();
                break;
                
            }
            case 0: {
                menu::exit_menu();
                break;
                
            }
        }

        std::cout << "\n"; // separate previous results from future reprint of menu
    }

    return EXIT_SUCCESS;
}