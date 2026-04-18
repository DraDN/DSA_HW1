#include <stdio.h>

#include "TimeLineManager.hpp"
#include <iostream>

void check_insert(tlm::ErrorType insert_result) {
    switch (insert_result) {
        case tlm::ErrorType::FAILURE_INVALID_ID:
            std::cout << "Insert failed: Invalid ID, no events with given ID in timeline\n";
            break;

        case tlm::ErrorType::FAILURE_IDS_NOT_ADJACENT:
            std::cout << "Insert failed: IDs not adjacent\n";
            break;

        case tlm::ErrorType::FAILURE_DUPLICATE_ID:
            std::cout << "Insert failed: Duplicate ID\n";
            break;

        case tlm::ErrorType::FAILURE_IDENTICAL_IDS:
            std::cout << "Insert failed: Identical IDs, cannot insert between the same event\n";
            break;
    
        case tlm::ErrorType::SUCCESS:
            std::cout << "Insert success\n";
            break;
    }
}

void check_relocate(tlm::ErrorType relocate_result) {
    switch (relocate_result)
    {
        case tlm::ErrorType::FAILURE_INVALID_ID:
            std::cout << "Relocate failed: Invalid ID, no events with given IDs in timeline\n";
            break;
        
        case tlm::ErrorType::FAILURE_IDENTICAL_IDS:
            std::cout << "Relocate failed: Identical IDs\n";
            break;
        
        case tlm::ErrorType::SUCCESS:
            std::cout << "Relocate success\n";
            break;
    }
}

void check_erase(tlm::ErrorType erase_result) {
    switch (erase_result)
    {
        case tlm::ErrorType::FAILURE_INVALID_ID:
            std::cout << "Erase failed: Invalid ID, no events with given ID in timeline\n";
            break;
        
        case tlm::ErrorType::SUCCESS:
            std::cout << "Erase success\n";
            break;
    }
}

int main() {
    tlm::TimeLineManager timeline;

    timeline.recordRecentEvent(1, "Quantum energy", 2300, 90);
    timeline.recordRecentEvent(2, "Mars colonization", 2350, 70);
    timeline.recordAncientEvent(0, "First contact", 2200, 100);

    std::cout << "Initial timeline: \n";
    timeline.displayChronology();
    std::cout << std::endl;

    auto insert_result = timeline.insertEventBetween(1, 2, tlm::Event(3, "Temporal crisis", 2400, 95));
    check_insert(insert_result);

    std::cout << "After insert: \n";
    timeline.displayChronology();
    std::cout << std::endl;

    auto relocate_result = timeline.relocateEvent(3, 0, false);
    check_relocate(relocate_result);

    std::cout << "After relocate: \n";
    timeline.displayChronology();
    std::cout << std::endl;

    auto erase_result = timeline.eraseCorruptedEvent(1);
    check_erase(erase_result);

    std::cout << "After erase: \n";
    timeline.displayChronology();
    std::cout << std::endl;

    unsigned int total_impact = timeline.computeTotalImpact();
    std::cout << "Total impact: " << total_impact << "\n";

    timeline.stabilizeTimeline(80);

    std::cout << "After stabilization: \n";
    timeline.displayChronology();
    std::cout << std::endl;

    return 0;
}