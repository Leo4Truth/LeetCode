#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution143 {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        stack<ListNode*> stk;
        ListNode* p = head;
        while (p) {
            stk.push(p);
            p = p->next;
        }
        ListNode* newHead = nullptr;
        ListNode* current = nullptr;
        ListNode* prev = nullptr;
        ListNode* p1 = head;
        ListNode* p2 = stk.top();
        stk.pop();
        while (p1 != p2 && p1->next != p2) {
            ListNode* tmp = p1->next;
            current = p1;
            p1->next = p2;
            p2->next = nullptr;
            if (!newHead) newHead = current;
            else prev->next = current;
            prev = current->next;
            p1 = tmp;
            p2 = stk.top();
            stk.pop();
        }
        if (p1 == p2) {
            prev->next = p1;
            p1->next = nullptr;
        }
        if (p1->next == p2) {
            prev->next = p1;
            p1->next = p2;
            p2->next = nullptr;
        }
    }

    // 2 Pointers, 3 Steps
    void reorderList_2Ptr(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // find the mid of the linked list
        ListNode* p1 = head;
        ListNode* p2 = head->next->next;
        while (p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode* mid = p1->next->next;
        p1->next->next = nullptr;
        

        // reverse the second part
        ListNode* p = mid;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* h2 = nullptr;
        while (p) {
            next = p->next;
            if (!next) h2 = p;
            p->next = prev;
            prev = p;
            p = next;
        }
#ifdef DEBUG
        cout << "reverse: ";
        p = h2;
        while (p) {
            cout << p->val;
            if (p->next) cout << "->";
            p = p->next;
        }
        cout << endl;
#endif // DEBUG

        // merge
        p1 = head;
        p2 = h2;
        prev = nullptr;
        while (p1 && p2) {
            ListNode* next1 = p1->next;
            ListNode* next2 = p2->next;
            p1->next = p2;
            if (prev) prev->next = p1;
            prev = p2; 
            p1 = next1;
            p2 = next2;
        }
        if (p1) prev->next = p1;
    }
};

int main(int argc, char* argv[]) {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);

    n1->next = n2;
    //n2->next = nullptr;
    n2->next = n3;
    //n3->next = nullptr;
    n3->next = n4;
    //n4->next = nullptr;
    n4->next = n5;
    //n5->next = nullptr;
    n5->next = n6;
    //n4->next = nullptr;
    n6->next = n7;
    n7->next = nullptr;

    ListNode* head = n1;

    ListNode* p = head;
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    Solution143 solution;
    solution.reorderList_2Ptr(head);

    p = head;
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    //system("pause");
    return 0;
}
