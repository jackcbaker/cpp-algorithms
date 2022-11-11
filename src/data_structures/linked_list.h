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

    T pop() {
        if (head == NULL) {
            return 0;
        }
        T dataOut = head->data;
        head = head->next;
        return dataOut;
    }

    void insert(T data) {
        LinkedListNode<T>* tmp = head;
        head = new LinkedListNode<T>(data, tmp);
    }

    void append(T data) {
        if (head == NULL) {
            head = new LinkedListNode<T>(data, NULL);
            return;
        }
        
        LinkedListNode<T>* traverser = head;
        while (traverser->next != NULL) {
            traverser = traverser->next;
        }
        traverser->next = new LinkedListNode<T>(data, NULL);
    }
};

#endif