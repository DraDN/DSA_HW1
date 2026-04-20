#pragma once

namespace menu {
    void display_menu();
    void add_task();
    void process_next_task();
    void undo_last_processed_task();
    void display_waiting_tasks();
    void display_processed_task_history();
    void process_next_k_tasks();
    void search_task_by_id();
    void display_statistics();
    void exit_menu();
}