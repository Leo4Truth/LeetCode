#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution142 {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        unordered_set<ListNode*> set;
        ListNode* p = head;
        set.insert(p);
        while (p) {
            p = p->next;
            if (set.find(p) == set.end()) set.insert(p);
            else return p;
        }
        return nullptr;
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

    Solution142 solution;
    ListNode* ans = solution.detectCycle(head);
    if (ans) cout << ans->val << endl;
    else cout << "NULL" << endl;

    //system("pause");
    return 0;
}
