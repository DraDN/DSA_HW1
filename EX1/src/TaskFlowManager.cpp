#include "TaskFlowManager.hpp"


std::ostream &tfm::operator<<(std::ostream &os, const Task &t) {
    os << "[ " << t.getId() << " | " << t.getDescription() << " | " << t.getPriority() << " ]";
    return os;
}


tfm::ErrorType tfm::TaskFlowManager::addTask(unsigned int id, const char* description, short priority) {
    if (!taskQueue.isEmpty() && searchTaskByID(id) != tools::nullopt) {
        return tfm::ErrorType::FAILURE_DUPLICATE_ID;
    }

    if (priority < TFM_TASK_PRIORITY_MIN || priority > TFM_TASK_PRIORITY_MAX) {
        return tfm::ErrorType::FAILURE_INVALID_PRIORITY;
    }

    taskQueue.enqueue(tfm::Task(id, description, priority));
    statistics.waitingTasks++;
    return tfm::ErrorType::SUCCESS;
}

tools::Queue<tfm::Task> tfm::TaskFlowManager::processNextTasks(unsigned int n) {
    tools::Queue<tfm::Task> output;

    for (unsigned int i = 0; i < n; i++) {
        if (taskQueue.isEmpty()) break;

        Task current = taskQueue.dequeue().value;
        output.enqueue(current);
        historyQueue.enqueue(current);

        statistics.waitingTasks--;
        statistics.processedTasks++;
    }

    return output;
}

tools::Optional<tfm::Task> tfm::TaskFlowManager::undoLastProcessedTask() {
    tools::Optional<Task> current = historyQueue.dequeue();

    if (current == tools::nullopt) return tools::nullopt;

    taskQueue.enqueue(current.value);

    statistics.waitingTasks++;
    statistics.processedTasks--;
    statistics.successfulUndos++;
    return current;
}

template <typename T>
static void display_queue(tools::Queue<T> queue) {
    while (!queue.isEmpty()) {
        std::cout << queue.dequeue().value << std::endl; // alright since `queue` parameter copies the original object
    }
}

void tfm::TaskFlowManager::displayWaitingTasks() {
    display_queue(taskQueue);
}

void tfm::TaskFlowManager::displayProcessHistory() {
    display_queue(historyQueue);
}

tools::Optional<tfm::Task> tfm::TaskFlowManager::searchTaskByID(unsigned int id) {
    tools::Optional<tfm::Task> result;
    tools::Queue<Task> unprocessed_bucket;
    tools::Queue<Task> processed_bucket;

    while (!taskQueue.isEmpty()) {
        auto current = taskQueue.peek();

        if (current.value.getId() == id) {
            result = current;
        }

        unprocessed_bucket.enqueue(taskQueue.dequeue().value);
    }

    while (!result.has_value && !historyQueue.isEmpty()) {
        auto current = historyQueue.peek();

        if (current.value.getId() == id) {
            result = current;
        }

        processed_bucket.enqueue(historyQueue.dequeue().value);
    }

    while (!unprocessed_bucket.isEmpty()) {
        taskQueue.enqueue(unprocessed_bucket.dequeue().value);
    }

    while (!processed_bucket.isEmpty()) {
        historyQueue.enqueue(processed_bucket.dequeue().value);
    }

    return result;
}
