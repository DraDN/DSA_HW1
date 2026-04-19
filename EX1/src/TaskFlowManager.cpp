#include "TaskFlowManager.hpp"


std::ostream &tfm::operator<<(std::ostream &os, const Task &t) {
    os << "[ " << t.getId() << " | " << t.getDescription() << " | " << t.getPriority() << " ]";
    return os;
}


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

Queue<tfm::Task> tfm::TaskFlowManager::processNextTasks(unsigned int n) {
    Queue<tfm::Task> output;

    for (unsigned int i = 0; i < n; i++) {
        if (taskQueue.isEmpty()) break;

        Task current = taskQueue.dequeue();
        output.enqueue(current);
        historyQueue.enqueue(current);

        statistics.waitingTasks--;
        statistics.processedTasks++;
    }

    return output;
}

std::optional<tfm::Task> tfm::TaskFlowManager::undoLastProcessedTask() {
    if (historyQueue.isEmpty()) return std::nullopt;

    Task current = historyQueue.dequeue();

    Queue<Task> bucket;
    while (!taskQueue.isEmpty()) {
        bucket.enqueue(taskQueue.dequeue());
    }

    taskQueue.enqueue(current);

    while (!bucket.isEmpty()) {
        taskQueue.enqueue(bucket.dequeue());
    }

    statistics.successfulUndos++;
    return std::make_optional<Task>(current);
}

template <typename T>
static void display_queue(Queue<T> queue) {
    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << std::endl; // alright since `queue` parameter copies the original object
    }
}

void tfm::TaskFlowManager::displayWaitingTasks() {
    display_queue(taskQueue);
}

void tfm::TaskFlowManager::displayProcessHistory() {
    display_queue(historyQueue);
}

std::optional<tfm::Task> tfm::TaskFlowManager::searchTaskByID(unsigned int id) {
    std::optional<tfm::Task> result(std::nullopt);
    Queue<Task> unprocessed_bucket;
    Queue<Task> processed_bucket;

    while (!taskQueue.isEmpty()) {
        auto current = taskQueue.peek();

        if (current.getId() == id) {
            result = std::make_optional<tfm::Task>(current);
        }

        unprocessed_bucket.enqueue(taskQueue.dequeue());
    }

    while (!result.has_value() && !historyQueue.isEmpty()) {
        auto current = historyQueue.peek();

        if (current.getId() == id) {
            result = std::make_optional<tfm::Task>(current);
        }

        processed_bucket.enqueue(historyQueue.dequeue());
    }

    while (!unprocessed_bucket.isEmpty()) {
        taskQueue.enqueue(unprocessed_bucket.dequeue());
    }

    while (!processed_bucket.isEmpty()) {
        historyQueue.enqueue(processed_bucket.dequeue());
    }

    return result;
}
