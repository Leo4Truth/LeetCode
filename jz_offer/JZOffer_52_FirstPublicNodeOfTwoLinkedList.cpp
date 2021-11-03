#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 || p2) {
            if (p1 == p2) return p1;
            p1 = p1 ? p1->next : headB;
            p2 = p2 ? p2->next : headA;
        }
        return nullptr;
    }
};

int main(int argc, char* argv[]) {
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
    ListNode* b1 = new ListNode(3);
    ListNode* b2 = new ListNode(4);
    ListNode* b3 = new ListNode(5);
    ListNode* c1 = new ListNode(6);
    ListNode* c2 = new ListNode(7);
    ListNode* c3 = new ListNode(8);

    c1->next = c2;
    c2->next = c3;

    a1->next = a2;
    a2->next = c1;

    b1->next = b2;
    b2->next = b3;
    b3->next = c1;

    Solution solution;
    cout << solution.getIntersectionNode(a1, b1)->val << endl;

    //system("pause");
    return 0;
}

