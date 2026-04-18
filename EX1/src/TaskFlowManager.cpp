#include "TaskFlowManager.hpp"

tfm::ErrorType tfm::TaskFlowManager::addTask(unsigned int id, const char* description, short priority) {
    if (!taskQueue.isEmpty() && searchTaskByID(id) != std::nullopt) {
        return tfm::ErrorType::FAILURE_DUPLICATE_ID;
    }

    if (priority < TFM_TASK_PRIORITY_MIN || priority > TFM_TASK_PRIORITY_MAX) {
        return tfm::ErrorType::FAILURE_INVALID_PRIORITY;
    }

    taskQueue.enqueue(tfm::Task(id, description, priority));
    statistics.waitingTasks++;
    return tfm::ErrorType::SUCCESS;
}

std::optional<tfm::Task> tfm::TaskFlowManager::searchTaskByID(unsigned int id) {
    std::optional<tfm::Task> result(std::nullopt);
    Queue<Task> bucket;

    while (!taskQueue.isEmpty()) {
        auto current = taskQueue.peek();

        if (current.getId() == id) {
            result = std::make_optional<tfm::Task>(current);
        }

        bucket.enqueue(taskQueue.dequeue());
    }

    while (!bucket.isEmpty()) {
        taskQueue.enqueue(bucket.dequeue());
    }

    return result;
}
