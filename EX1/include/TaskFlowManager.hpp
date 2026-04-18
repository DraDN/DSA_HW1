#pragma once

#include <iostream>
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

    /// @struct Task
    /// 
    /// @brief A task in the TaskFlowManager
    struct Task {
        public:
            Task() : id(0), description(""), priority(1) {};
            Task(unsigned int id, const char* description, short priority) : id(id), description(description), priority(priority) {};

            unsigned int getId() const { return id; }
            const char* getDescription() const { return description; }
            short getPriority() const { return priority; }

        private:
            unsigned int id; /// unique positive integer identifier
            const char* description; /// string literal with a short description
            short priority; /// integer between 1 and 5
    };
    std::ostream& operator<<(std::ostream& os, const Task& t);

    /// @brief Statistics of the TaskFlowManager
    /// 
    /// Contains the number of waiting tasks, processed tasks and successful undos
    struct TaskFlowManagerStatistics {
        unsigned int waitingTasks = 0;
        unsigned int processedTasks = 0;
        unsigned int successfulUndos = 0;
    };

    /// @class TaskFlowManager
    ///
    /// @brief Manages a queue of tasks
    ///
    /// With functions to add, process and undo tasks
    class TaskFlowManager {
        public:
            TaskFlowManager() {};

            /// @brief Adds a new task to the waiting list
            /// @param id unique positive integer identifier
            /// @param description string literal with a short description
            /// @param priority integer between 1 and 5
            /// @return `ErrorType::FAILURE_DUPLICATE_ID` - if ID is already in use
            ///
            /// `ErrorType::FAILURE_INVALID_PRIORITY` - if priority is not between 1 and 5
            /// 
            /// `ErrorType::SUCCESS` - if the task was added successfully
            ErrorType addTask(unsigned int id, const char* description, short priority);

            /// @brief Processes n tasks from the waiting list
            /// @param n the number of tasks to process
            /// @return a `Queue<Task>` containing the processed tasks, in order
            Queue<Task> processNextTasks(unsigned int n = 1);

            /// @brief Undoes the last processing of a task
            /// @return `std::optional<Task>` containing the undone task
            ///
            /// `std::nullopt` if there are no tasks to undo
            std::optional<Task> undoLastProcessedTask();

            void displayWaitingTasks();
            
            /// @brief Displays the prcessed tasks history
            void displayProcessHistory();

            /// @brief Searches for a task (done or not) by ID
            /// @param id the ID to search for
            /// @return `std::optional<Task>` containing the task
            ///
            /// `std::nullopt` if the task was not found
            std::optional<Task> searchTaskByID(unsigned int id);

            /// @brief Returns the statistics of the TaskFlowManager
            /// @return `TaskFlowManagerStatistics` containing the values
            TaskFlowManagerStatistics getStatistics() { return statistics; }

        private:
            Queue<Task> taskQueue;
            Queue<Task> historyQueue;
            TaskFlowManagerStatistics statistics;
    };
}
