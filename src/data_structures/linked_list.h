#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <typename T> 
class LinkedListNode
{
public:
    LinkedListNode<T>* next;
    T data;

    LinkedListNode(T dataIn, LinkedListNode<T>* nextIn) {
        data = dataIn;
        next = nextIn;
    }
};

template <typename T> 
class LinkedList
{
public:
    LinkedListNode<T>* head {};

    T popLeft() {
        if (head == nullptr) {
            return T();
        }
        T dataOut = head->data;
        head = head->next;
        return dataOut;
    }

    T pop() {
        if (head == nullptr) {
            return T();
        }
        LinkedListNode<T>* traverser = head;
        if (traverser->next == nullptr) {
            head = nullptr;
            return traverser->data;
        }
        LinkedListNode<T>* traverserNext = head->next;
        while (traverserNext->next != nullptr) {
            traverser = traverser->next;
            traverserNext = traverserNext->next;
        }
        traverser->next = nullptr;
        return traverserNext->data;
    }

    void insert(T data) {
        LinkedListNode<T>* tmp = head;
        head = new LinkedListNode<T>(data, tmp);
    }

    void append(T data) {
        if (head == nullptr) {
            head = new LinkedListNode<T>(data, nullptr);
            return;
        }
        LinkedListNode<T>* traverser = head;
        while (traverser->next != nullptr) {
            traverser = traverser->next;
        }
        traverser->next = new LinkedListNode<T>(data, nullptr);
    }
};

#endif