#ifndef LINKED_LIST_SIMPLE_H
#define LINKED_LIST_SIMPLE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode addLists(ListNode* lhs, ListNode* rhs);

#endif