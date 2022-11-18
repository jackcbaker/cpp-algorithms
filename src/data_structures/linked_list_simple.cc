#include "linked_list_simple.h"

ListNode addLists(ListNode* lhs, ListNode* rhs) {
    if ((lhs->val == 0) and (rhs->val == 0)) {
        return ListNode(0);
    }
    bool endBothLists = false;
    ListNode output = ListNode();
    ListNode* currNode = output;

    while (!endBothLists) {
    };
}