#include <iostream>
#include <assert.h>

#include "TaskFlowManager.hpp"

int main() {
    tfm::TaskFlowManager task_manager;
    task_manager.addTask(100, "Task 1", 1);
    tools::Queue<tfm::Task> processed_tasks = task_manager.processNextTasks();

    assert(processed_tasks.getSize() == 1);

    task_manager.addTask(101, "Task 2", 1);
    task_manager.addTask(102, "Task 3", 1);
    task_manager.addTask(103, "Task 4", 1);

    tools::Queue<tfm::Task> processed_tasks_2 = task_manager.processNextTasks(2);

    assert(processed_tasks_2.getSize() == 2);

    return 0;
}