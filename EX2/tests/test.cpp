#include <stdio.h>

#include "TimeLineManager.hpp"

void check_insert(tlm::ErrorType insert_result) {
    if (insert_result == tlm::ErrorType::FAILURE_IDS_NOT_ADJACENT) {
        printf("Insert failed: IDs not adjacent\n");
    } else if (insert_result == tlm::ErrorType::FAILURE_DUPLICATE_ID) {
        printf("Insert failed: Duplicate ID\n");
    } else if (insert_result == tlm::ErrorType::SUCCESS) {
        printf("Insert success\n");
    }
}

int main() {
    tlm::TimeLineManager timeline;
    timeline.recordAncientEvent(100, "Event 1", 1000, 10);
    timeline.recordAncientEvent(200, "Event 2", 900, 10);
    timeline.recordRecentEvent(300, "Event 3", 1900, 10);

    timeline.displayChronology();
    printf("\n");
    
    auto insert_result = timeline.insertEventBetween(200, 100, tlm::Event(300, "Event 4", 800, 10));
    check_insert(insert_result);
    auto insert2_result = timeline.insertEventBetween(200, 300, tlm::Event(400, "Event 5", 700, 10));
    check_insert(insert2_result);
    auto insert3_result = timeline.insertEventBetween(200, 100, tlm::Event(400, "Event 6", 600, 10));
    check_insert(insert3_result);
    printf("\n");
    
    timeline.displayChronology();
    // static_assert(1 == 1);
    // printf("Hello, World From Test EX2!\n");
    return 0;
}