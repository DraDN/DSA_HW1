#pragma once

#include "LinkedList.h"


namespace tlm {
    enum ErrorType {

    };
    
    struct Event {
        int id;
        string descrition;
        int year;
        int impact;
    };

    class TimeLineManager {
        private:
        LinkedList<Event> list;

        public:
        void recordAncientEvent(Event e) {
            list.addFirst(e);
        }

        void recorRecentEvent(Event e) {
            list.addLast(e);
        }

        void insertEventBetween(int leftId, int rightId, Event e) {
            Node<Event>* current = list.pfirst;

            while (current != NULL) {
                if(current->info.id == leftId){
                    if(current->next != NULL && current->next->info.id == rightId) {
                        Node<Event>* newEvent = new Node<Event>;
                        newEvent->info = e;

                        Node<Event>* rightId = current->next;

                        newEvent->next = rightId;
                        newEvent->prev = current;
                        current->next = newEvent;
                        rightId->prev = newEvent;


                    }
                }

                current = current->next;
            }
            cout << "IDs are not next to eachother: " << leftId << " - " << rightId << endl;

        }

        void eraseCorruptedEvent(int id) {

        }

        void relocateEvent(int idToMove, int newNeighborID, bool before) {

        }

        void displayChronology() {
            if(list.isEmpty()) {
                cout << "Timeline is empty. \n";
            }

        }

        void computeTotalImpact() {

        }

        void stabilizeTimeline(int threshold) {
            
        }


    };
}
