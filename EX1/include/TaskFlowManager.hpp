#pragma once

#include <optional>

#include "Source_Queue.h"


namespace tfm {
    enum ErrorType {
        SUCCESS,
        FAILURE_DUPLICATE_ID,
        FAILURE_INVALID_PRIORITY,
        FAILURE
    };

    #define TFM_TASK_PRIORITY_MIN 1
    #define TFM_TASK_PRIORITY_MAX 5

    struct Task {
        public:
            Task() : id(0), description(""), priority(1) {};
            Task(unsigned int id, const char* description, short priority) : id(id), description(description), priority(priority) {};

            unsigned int getId() { return id; }
            const char* getDescription() { return description; }
            short getPriority() { return priority; }
        private:
            unsigned int id;
            const char* description;
            short priority;
    };

    struct TaskFlowManagerStatistics {
        unsigned int waitingTasks = 0;
        unsigned int processedTasks = 0;
        unsigned int successfulUndos = 0;
    };

    class TaskFlowManager {
        public:
            TaskFlowManager() {};

            ErrorType addTask(unsigned int id, const char* description, short priority);
            // ErrorType processNextTask();
            ErrorType processNextTasks(unsigned int n = 1);
            ErrorType undoLastProcessedTask();

            void displayWaitingTasks();
            void displayProcessHistory();

            std::optional<Task> searchTaskByID(unsigned int id);

        private:
            // TODO: Add undo's structure
            // TODO: Add process history structure
            Queue<Task> taskQueue;
            TaskFlowManagerStatistics statistics;
    };
}
