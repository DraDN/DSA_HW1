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
    static std::string description;
    short priority;

    std::cin >> id;
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

void menu::process_next_task() {
    tools::Queue<tfm::Task> processResult = task_manager.processNextTasks(1);

    if (processResult.isEmpty()) {
        std::cout << "No more waiting tasks.\n";
    }
    else {
        tfm::Task t = processResult.dequeue().value;
        std::cout << "Processed task: \n";
        std::cout << "ID: " << t.getId() << ", Description: " << t.getDescription() << ", Priority: " << t.getPriority() << std::endl;
    }

}

void menu::undo_last_processed_task() {
    auto result = task_manager.undoLastProcessedTask();

    if (result.has_value) {
        std::cout << "Undo succcessful. Restored task: \n";
        std::cout << "ID: " << result->getId() << ", Description: " << result->getDescription() << ", Priority: " << result->getPriority() << "\n";
    }
    else {
        std::cout << "No processed task available for undo.\n";
    }
}

void menu::display_waiting_tasks() {
    if (task_manager.getStatistics().waitingTasks == 0){
        std::cout << "No waiting taks. \n";
        return;
    }
    std::cout << "Waiting tasks:\n";
    task_manager.displayWaitingTasks();
}

void menu::display_processed_task_history() {
    if (task_manager.getStatistics().processedTasks == 0) {
        std::cout << "No processed tasks. \n";
        return;
    }
    std::cout << "Processed task history:\n";
    task_manager.displayProcessHistory();
}

void menu::process_next_k_tasks() {
    unsigned int k;
    std::cin >> k;

    if (!std::cin || k == 0) {
        std::cout << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        return;
        
    }
    std::cout << "Requested to process " << k << " task(s). \n";

    tools::Queue<tfm::Task> processedTasks = task_manager.processNextTasks(k);

    if (processedTasks.isEmpty()) {
        std::cout << "No waiting tasks to process. \n";
        return;
    }

    while (!processedTasks.isEmpty()) {
        tfm::Task t = processedTasks.dequeue().value;
        std::cout << "\n Processed tasks: \n";
        std::cout << "ID: " << t.getId() << ", Description: " << t.getDescription() << ", Priority: " << t.getPriority() << "\n";
    }
}

void menu::search_task_by_id() {
    unsigned int id;
    std::cout <<"Enter Id to search: ";
    std::cin >> id;

    auto result = task_manager.searchTaskByID(id);

    if (result.has_value) {
        std::cout << "Task found: \n";
        std::cout << "ID: " << result->getId() << ", Description: " << result->getDescription() << ", Priority: " << result->getPriority() << "\n";

    }
    else {
        std::cout << "Task with Id " << id << " not found in waiting queue or history. \n";
    }
}

void menu::display_statistics() {
    tfm::TaskFlowManagerStatistics stats = task_manager.getStatistics();

    std::cout << "Statistics: \n";
    std::cout << "Waiting tasks: " << stats.waitingTasks << "\n";
    std::cout << "Processed tasks: " << stats.processedTasks << "\n";
    std::cout << "Successful undooperations: " << stats.successfulUndos << "\n";

}


void menu::exit_menu() {
    std::cout << "Program terminated.";
}

