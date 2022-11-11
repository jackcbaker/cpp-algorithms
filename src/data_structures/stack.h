#ifndef STACK_H
#define STACK_H

template <typename T>
struct StackNode
{
    T data;
    StackNode<T>* next;

    StackNode(T dataIn, StackNode<T>* nextIn) {
        data = dataIn;
        next = nextIn;
    }
};


template <typename T>
class Stack 
{
    public:
        StackNode<T>* head = nullptr;
    
    T peek() {
        if (head == nullptr) {
            return T();
        }
        return head->data;
    }

    T pop() {
        if (head == nullptr) {
            return T();
        }
        T output = head->data;
        head = head->next; 
        return output;
    }

    void insert(T data) {
        StackNode<T>* headPrev = head;
        head = new StackNode<T>(data, headPrev);
    }

};

#endif