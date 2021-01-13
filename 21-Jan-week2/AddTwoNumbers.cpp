#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        ListNode* current = nullptr;

        auto *p1 = l1, *p2 = l2;
        while (p1 && p2) {
            int tmp = p1->val + p2->val + carry;
            carry = tmp > 9 ? 1 : 0;
            tmp %= 10;
            current = new ListNode(tmp);
            if (!head) head = current;
            else prev->next = current;
            prev = current;
            p1 = p1->next;
            p2 = p2->next;
        }

        while (p1) {
            int tmp = p1->val + carry;
            carry = tmp > 9 ? 1 : 0;
            tmp %= 10;

            p1->val = tmp;
            prev->next = p1;
            prev = p1;
            p1 = p1->next;
        }
        while (p2) {
            int tmp = p2->val + carry;
            carry = tmp > 9 ? 1 : 0;
            tmp %= 10;

            p2->val = tmp;
            prev->next = p2;
            prev = p2;
            p2 = p2->next;
        }

        if (carry == 1) {
            current = new ListNode(1);
            prev->next = current;
            prev = current;
        } 

        return head;
    }
};