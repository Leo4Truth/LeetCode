#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return nullptr;
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        ListNode* current = nullptr;
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        while (p1 && p2) {
            if (p1->val < p2->val) {
                current = p1;
                p1 = p1->next;
            }
            else {
                current = p2;
                p2 = p2->next;
            }
            if (!head) head = current;
            else prev->next = current;
            prev = current;
        }

        if (p1) prev->next = p1;
        else if (p2) prev->next = p2;

        return head;
    }
};