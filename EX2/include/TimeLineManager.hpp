#pragma once

// #include <iostream>
#include <ostream>
// #include <optional>

// #include "LinkedList.h"
#include "LinkedList.hpp"
#include "Optional.hpp"


namespace tlm {
    enum ErrorType {
        SUCCESS,
        FAILURE_INVALID_ID,
        FAILURE_DUPLICATE_ID,
        FAILURE_IDS_NOT_ADJACENT,
        FAILURE_IDENTICAL_IDS,
        FAILURE
    };
    
    /// @struct Event
    /// 
    /// @brief A structure representing an event in a timeline
    struct Event {
        public: 
            Event() : id(0), description(""), year(0), impact(0) {};
            Event(int id, const char* description, int year, int impact) : id(id), description(description), year(year), impact(impact) {}

            unsigned int getId() const { return id; }
            const char* getDescription() const { return description; }
            unsigned int getYear() const { return year; }
            unsigned int getImpact() const { return impact; }

        private:       
            unsigned int id; /// unique positive integer
            const char* description; /// string literal with description
            unsigned int year; /// the year of the event
            unsigned int impact; /// the historical impact of the event
    };
    std::ostream& operator<<(std::ostream& os, const Event& e);

    /// @class TimeLineManager
    /// @brief Manages a timeline of events
    /// 
    /// This class provides functions to add, insert, search, erase and display events from a timeline.
    ///
    /// It also provides functions to compute the total historical impact of all events in the timeline or to stabilize the timeline via a threshold
    class TimeLineManager {
        public:
            /// @brief Adds a new event at the start of the timeline
            /// @param id unique postive integer
            /// @param description string literal with a short description
            /// @param year the year of the event
            /// @param impact the historical impact of the event
            /// @return tlm::ErrorType::FAILURE_DUPLICATE_ID if ID is already in use, otherwise tlm::ErrorType::SUCCESS
            ErrorType recordAncientEvent(unsigned int id, const char* description, unsigned int year, unsigned int impact);

            /// @brief Adds a new event at the start of the timeline
            /// @param e the event to add
            /// @return tlm::ErrorType::FAILURE_DUPLICATE_ID if ID is already in use, otherwise tlm::ErrorType::SUCCESS
            ErrorType recordAncientEvent(Event e);

            /// @brief Adds a new event at the end of the timeline
            /// @param id unique postive integer
            /// @param description string literal with a short description
            /// @param year the year of the event
            /// @param impact the historical impact of the event
            /// @return tlm::ErrorType::FAILURE_DUPLICATE_ID if ID is already in use, otherwise tlm::ErrorType::SUCCESS
            ErrorType recordRecentEvent(unsigned int id, const char* description, unsigned int year, unsigned int impact);

            /// @brief Adds a new event at the end of the timeline
            /// @param e the event to add
            /// @return tlm::ErrorType::FAILURE_DUPLICATE_ID if ID is already in use, otherwise tlm::ErrorType::SUCCESS
            ErrorType recordRecentEvent(Event e);


            /// @brief Inserts a new event between two existing events
            /// @param leftId the first ID to place between
            /// @param rightId the second ID to place between
            /// @param e the event to insert
            /// @return `tlm::ErrorType::FAILURE_IDENTICAL_IDS` - if `leftId` and `rightId` are have the same value,
            /// 
            /// `tlm::ErrorType::FAILURE_DUPLICATE_ID` - if the ID of the event to insert is already in use,
            /// 
            /// `tlm::ErrorType::FAILURE_INVALID_ID` - if either of the IDs don't correspond to existing events,
            /// 
            /// `tlm::ErrorType::FAILURE_IDS_NOT_ADJACENT` - if the IDs are not next to each other,
            ///
            /// `tlm::ErrorType::SUCCESS` - if the event was successfully inserted
            ErrorType insertEventBetween(unsigned int leftId, unsigned int rightId, Event e);


            /// @brief Relocates an event in the timeline
            /// @param idToMove the ID of the event to be moved
            /// @param newNeighborID the ID of the event around which the event will be moved
            /// @param before `true` if the event will be moved before the neighbor, `false` if the event will be moved after the neighbor
            /// @return `tlm::ErrorType::FAILURE_INVALID_ID` - if either of the IDs don't correspond to existing events,
            /// 
            /// `tlm::ErrorType::FAILURE_IDENTICAL_IDS` - if both IDs are identical,
            /// 
            /// `tlm::ErrorType::SUCCESS` - if the event was successfully moved
            ErrorType relocateEvent(unsigned int idToMove, unsigned int newNeighborID, bool before);


            /// @brief Erases an event from the timeline
            /// @param id the ID of the event to erase
            /// @return `tlm::ErrorType::FAILURE_INVALID_ID` - if the ID doesn't correspond to an existing event
            /// 
            /// `tlm::ErrorType::SUCCESS` - if the event was successfully erased
            ErrorType eraseCorruptedEvent(unsigned int id);


            /// @brief Prints the events in the timeline
            ///
            /// If the timeline is empty, prints `"Timeline is empty."`
            void displayChronology();


            /// @brief Computes the total impact of all events in the timeline
            /// @return `unsigned int` equal to the total impact of timeline
            unsigned int computeTotalImpact();

            /// @brief Puts all the events with the `impact` above `threshold` at the start of the timeline, while preserving relative structure
            /// @param threshold the value that `impact` needs to be higher or equal to in order to be moved
            void stabilizeTimeline(int threshold);
        
        private:
            /// @brief Searches for an event by its ID
            /// @param id the ID of the event to search for
            /// @return If the event is found - `std::optional<Node<tlm::Event>*>` - optional with the value of the pointer to the node containing the event,
            /// 
            /// Otwerwise - `std::nullopt` - if the event is not found
            // std::optional<Node<Event>*> search_event_by_id(unsigned int id);
            tools::Optional<tools::LinkedList<Event>::Node*> search_event_by_id(unsigned int id);

        private:
            // LinkedList<Event> list;
            tools::LinkedList<Event> list;

    };
}
