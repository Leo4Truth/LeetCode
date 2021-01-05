#include <iostream>
#include "lib/ListNode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* p1 = head;
        ListNode* p2 = head;

        while (p1 && p2) {
            while (p2->next && p2->val == p2->next->val) p2 = p2->next;
            
            if (p1 != p2) {
                if (prev) prev->next = p2->next;
                else head = p2->next; 
            }
            else prev = p1;

            p1 = p2->next;
            p2 = p2->next;
        }
    }
};