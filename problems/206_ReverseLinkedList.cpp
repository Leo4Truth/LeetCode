#include <iostream>
#include <vector>

using namespace std;

#define DEBUG

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}
};

class Solution206 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main(int argc, char* argv[]) {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    Solution206 solution;
    ListNode* p = solution.reverseList(n1);
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    //system("pause");
    return 0;
}
