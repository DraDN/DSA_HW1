#include "LinkedList.hpp"

template <typename T>
void tools::LinkedList<T>::addFirst(T element) {
    tools::LinkedList<T>::Node *aux = new tools::LinkedList<T>::Node;

    aux->value = element;
    aux->prev = nullptr;
    aux->next = pfirst;

    if (pfirst != nullptr) pfirst->prev = aux;

    pfirst = aux;

    if (plast == nullptr) plast = pfirst;   
}

template <typename T>
void tools::LinkedList<T>::addLast(T element) {
    tools::LinkedList<T>::Node *aux = new tools::LinkedList<T>::Node;

    aux->value = element;
    aux->prev = plast;
    aux->next = nullptr;

    if (plast != nullptr) plast->next = aux;

    plast = aux;

    if (pfirst == nullptr) pfirst = plast;
}

template <typename T>
tools::LinkedList_t::ResultType tools::LinkedList<T>::removeFirst() {
    if (pfirst == nullptr) return tools::LinkedList_t::ResultType::FAILURE;

    tools::LinkedList<T>::Node* aux = pfirst->next;

    if (pfirst == plast) plast = nullptr;

    delete pfirst;

    pfirst = aux;

    if (pfirst != nullptr) pfirst->prev = nullptr;

    return tools::LinkedList_t::ResultType::SUCCESS;
}

template <typename T>
tools::LinkedList_t::ResultType tools::LinkedList<T>::removeLast() {
    if (plast == nullptr) return tools::LinkedList_t::ResultType::FAILURE;

    tools::LinkedList<T>::Node* aux = plast->prev;

    if (pfirst == plast) pfirst = nullptr;

    delete plast;

    plast = aux;

    if (plast != nullptr) plast->next = nullptr;

    return tools::LinkedList_t::ResultType::SUCCESS;
}
