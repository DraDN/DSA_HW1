#pragma once

namespace tools {

    class LinkedList_t {
        public:
            enum class ResultType {
                SUCCESS,
                FAILURE
            };
    };

    template <typename T>
    class LinkedList : public LinkedList_t
    {
        public: 
            struct Node {
                T value;
                Node* next = nullptr;
                Node* prev = nullptr;
            };
        
        public:
            void addFirst(T element);
            void addLast(T element);

            T getValue (Node* p) { return p->value; }

            ResultType removeFirst();
            ResultType removeLast();

            bool isEmpty() { return (pfirst == NULL); }

        public:
            Node* pfirst = nullptr;
            Node* plast = nullptr;
    };

}

#include "LinkedList.tpp"