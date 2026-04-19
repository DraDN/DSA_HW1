#include <iostream>
#include <assert.h>

#include "TaskFlowManager.hpp"

int main() {
    tfm::TaskFlowManager task_manager;
    task_manager.addTask(100, "Task 1", 1);
    Queue<tfm::Task> processed_tasks = task_manager.processNextTasks();

    size_t size = 0;
    while (!processed_tasks.isEmpty()) {
        size++;
        processed_tasks.dequeue();
    }

    assert(size == 1);

    task_manager.addTask(101, "Task 2", 1);
    task_manager.addTask(102, "Task 3", 1);
    task_manager.addTask(103, "Task 4", 1);

    Queue<tfm::Task> processed_tasks_2 = task_manager.processNextTasks(2);
    size = 0;
    while (!processed_tasks_2.isEmpty()) {
        size++;
        processed_tasks_2.dequeue();
    }

    assert(size == 2);

    return 0;
}