#include <iostream>
#include <assert.h>
#include <optional>

#include "TaskFlowManager.hpp"

int main() {
    tfm::TaskFlowManager task_manager;

    task_manager.addTask(100, "Task 1", 1);
    task_manager.addTask(101, "Task 2", 1);
    
    const std::optional<tfm::Task> undo_result = task_manager.undoLastProcessedTask();
    assert(undo_result == std::nullopt);

    for (short i = 0; i < 2; i++) {
        task_manager.processNextTasks();

        const std::optional<tfm::Task> undo_result_2 = task_manager.undoLastProcessedTask();
        std::cout << undo_result_2.value() << std::endl;
        assert(undo_result_2 != std::nullopt);
        assert(undo_result_2->getId() == 100);
        assert(undo_result_2->getDescription() == "Task 1");
        assert(undo_result_2->getPriority() == 1);
    }

    return 0;
}