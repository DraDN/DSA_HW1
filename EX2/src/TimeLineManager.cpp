#include "TimeLineManager.hpp"


ostream& tlm::operator<<(ostream& os, const Event& e) {
    os << "[ " << e.getId() << " | " << e.getDescription() << " | " << e.getYear() << " | " << e.getImpact() << " ]";
    return os;
}


std::optional<Node<tlm::Event>*> tlm::TimeLineManager::search_event_by_id(unsigned int id) {
    Node<Event>* current = list.pfirst;

    while (current != nullptr) {
        if (current->info.getId() == id) {
            return std::make_optional<Node<Event>*>(current);
        }
        current = current->next;
    }
    return std::nullopt;
}


/// @brief Macro for checking if ID is already in use in `list`
/// 
/// Makes function return `tlm::ErrorType::FAILURE_DUPLICATE_ID` if ID is already in use
#define CHECK_DUPPLICATE_ID(id) if (!list.isEmpty() && search_event_by_id(id) != std::nullopt) return tlm::ErrorType::FAILURE_DUPLICATE_ID

tlm::ErrorType tlm::TimeLineManager::recordAncientEvent(unsigned int id, const char* description, unsigned int year, unsigned int impact) {
    CHECK_DUPPLICATE_ID(id);
    list.addFirst(Event(id, description, year, impact));
    return tlm::ErrorType::SUCCESS;
}

tlm::ErrorType tlm::TimeLineManager::recordRecentEvent(unsigned int id, const char* description, unsigned int year, unsigned int impact) {
    CHECK_DUPPLICATE_ID(id);
    list.addLast(Event(id, description, year, impact));
    return tlm::ErrorType::SUCCESS;
}

tlm::ErrorType tlm::TimeLineManager::recordAncientEvent(Event e) {
    CHECK_DUPPLICATE_ID(e.getId());
    list.addFirst(e);
    return tlm::ErrorType::SUCCESS;
}

tlm::ErrorType tlm::TimeLineManager::recordRecentEvent(Event e) {
    CHECK_DUPPLICATE_ID(e.getId());
    list.addLast(e);
    return tlm::ErrorType::SUCCESS;
}

/*
    Finds `leftID` and then checks it's neighbours
    If it finds `rigthID`, then it will insert `e` between them
*/
tlm::ErrorType tlm::TimeLineManager::insertEventBetween(unsigned int leftId, unsigned int rightId, Event e) {
    if (leftId == rightId) return tlm::ErrorType::FAILURE_IDENTICAL_IDS;

    CHECK_DUPPLICATE_ID(e.getId());

    std::optional<Node<Event>*> current = search_event_by_id(leftId);
    if (!current.has_value()) return tlm::ErrorType::FAILURE_INVALID_ID; 
    if (current.value()->next == nullptr && current.value()->prev == nullptr) return tlm::ErrorType::FAILURE; // if list has only one element
    
    Node<Event>* neighbour = nullptr;

    bool is_neighbour_right = (current.value()->next != nullptr && current.value()->next->info.getId() == rightId);
    bool is_neightbour_left = (current.value()->prev != nullptr && current.value()->prev->info.getId() == rightId);

    Node<Event>* newEvent = new Node<Event>;
    newEvent->info = e;

    if (is_neighbour_right) {
        neighbour = current.value()->next;

        // make connections for inserted event
        newEvent->next = neighbour;
        newEvent->prev = current.value();

        // replace connections of neighbours
        current.value()->next = newEvent;
        neighbour->prev = newEvent;
    } else if (is_neightbour_left) {
        neighbour = current.value()->prev;

        // make connections for inserted event
        newEvent->next = current.value();
        newEvent->prev = neighbour;

        // replace connections of neighbours
        current.value()->prev = newEvent;
        neighbour->next = newEvent;
    } 
    else return tlm::ErrorType::FAILURE_IDS_NOT_ADJACENT;

    return tlm::ErrorType::SUCCESS;
}

tlm::ErrorType tlm::TimeLineManager::relocateEvent(unsigned int idToMove, unsigned int newNeighborID, bool before) {
    if (idToMove == newNeighborID) return tlm::ErrorType::FAILURE_IDENTICAL_IDS;

    std::optional<Node<Event>*> to_move = search_event_by_id(idToMove);
    if (!to_move.has_value()) return tlm::ErrorType::FAILURE_INVALID_ID;

    std::optional<Node<Event>*> neighbour = search_event_by_id(newNeighborID);
    if (!neighbour.has_value()) return tlm::ErrorType::FAILURE_INVALID_ID;

    if (before) {
        // patch old connections
        to_move.value()->prev->next = to_move.value()->next;
        to_move.value()->next->prev = to_move.value()->prev;

        // make new connections for moved
        to_move.value()->next = neighbour.value();
        to_move.value()->prev = neighbour.value()->prev;

        // make new connections for neighbour
        neighbour.value()->prev->next = to_move.value();
        neighbour.value()->prev = to_move.value();
    } else {
        // patch old connections
        to_move.value()->prev->next = to_move.value()->next;
        to_move.value()->next->prev = to_move.value()->prev;

        // make new connections
        to_move.value()->next = neighbour.value()->next;
        to_move.value()->prev = neighbour.value();

        // make new connections for neighbour
        neighbour.value()->next->prev = to_move.value();
        neighbour.value()->next = to_move.value();
    }

    return tlm::ErrorType::SUCCESS;
}

tlm::ErrorType tlm::TimeLineManager::eraseCorruptedEvent(unsigned int id) {
    std::optional<Node<Event>*> to_delete = search_event_by_id(id);

    if (!to_delete.has_value()) return tlm::ErrorType::FAILURE_INVALID_ID;

    if (to_delete.value()->prev == nullptr) list.pfirst = to_delete.value()->next; // check if at start of list
    else to_delete.value()->prev->next = to_delete.value()->next;

    if (to_delete.value()->next == nullptr) list.plast = to_delete.value()->prev; // check if at end of list
    else to_delete.value()->next->prev = to_delete.value()->prev;

    delete to_delete.value();
    return tlm::ErrorType::SUCCESS;
}

void tlm::TimeLineManager::displayChronology() {
    if(list.isEmpty()) {
        cout << "Timeline is empty. \n";
    }

    Node<Event>* current = list.pfirst;
    while (current != nullptr) {
        std::cout << current->info << std::endl;
        current = current->next;
    }
}

unsigned int tlm::TimeLineManager::computeTotalImpact() {
    unsigned int total = 0;

    Node<Event>* current = list.pfirst;
    while (current != nullptr) {
        total += current->info.getImpact();
        current = current->next;
    }

    return total;
}

/* 
    Goes through list while keeping track of the location after the last moved event (starts at the first element) (in order to keep structure)
    If the impact of the current event is >= than the threshold, the current event is moved after the last moved event via `relocateEvent`
    It does this by putting it before the next element after the last moved event
    Then updates the auxiliary location
*/
void tlm::TimeLineManager::stabilizeTimeline(int threshold) {
    Node<Event>* current = list.pfirst;
    Node<Event>* end_of_sort_location = list.pfirst;

    while (current != nullptr) {
        if (current->info.getImpact() >= threshold) {
            relocateEvent(current->info.getId(), end_of_sort_location->info.getId(), true);
            end_of_sort_location = current->next;
        }

        current = current->next;
    }
}
