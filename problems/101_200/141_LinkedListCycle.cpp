#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution141 {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* p1 = head;
        ListNode* p2 = head->next->next;
        while (p2 && p2->next) {
            if (p1 == p2) return true;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;
    //n5->next = n2;

    ListNode* head = n1;

    Solution141 solution;
    cout << solution.hasCycle(head) << endl;

    //system("pause");
    return 0;
}
